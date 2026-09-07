class Solution {
public:
    int distinctSubseqII(string s) {
        long long dp = 0;
        int MOD = 1e9 + 7;
        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long newDp = (dp * 2 + 1 - last[idx] + MOD) % MOD;

            last[idx] = (dp + 1) % MOD;

            dp = newDp;
        }
        return dp;
    }
};