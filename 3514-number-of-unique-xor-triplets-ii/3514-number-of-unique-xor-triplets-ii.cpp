class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        const int MAXX = 2048;

        vector<bool> pair(MAXX, false);
        vector<bool> ans(MAXX, false);

        int n = nums.size();

        // XOR of every pair (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pair[nums[i] ^ nums[j]] = true;
            }
        }

        // Add third element
        for (int x = 0; x < MAXX; x++) {
            if (!pair[x]) continue;

            for (int num : nums) {
                ans[x ^ num] = true;
            }
        }

        int cnt = 0;
        for (bool x : ans)
            if (x) cnt++;

        return cnt;
    }
};