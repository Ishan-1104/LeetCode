class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int len = 0;
        vector<int> dp(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 &&
                ((s[i] - s[i - 1] == 1) || (s[i - 1] == 'z' && s[i] == 'a'))) {
                len++;
            } else {
                len = 1;
            }

            int idx = s[i] - 'a';
            dp[idx] = max(dp[idx], len);
        }
        int ans = 0;
        for (int x : dp) {
            ans += x;
        }
        return ans;
    }
};