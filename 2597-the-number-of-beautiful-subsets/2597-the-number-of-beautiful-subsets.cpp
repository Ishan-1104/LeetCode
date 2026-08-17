class Solution {
public:
    int solve(vector<int>& nums, int i, int k,
              unordered_map<int, int>& freq) {

        if (i == nums.size())
            return 1;   
        int ans = solve(nums, i + 1, k, freq);

        if (freq[nums[i] - k] == 0) {

            freq[nums[i]]++;

            ans += solve(nums, i + 1, k, freq);

            freq[nums[i]]--;
        }

        return ans;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        sort(nums.begin() , nums.end());

        return solve(nums, 0, k, freq) - 1;
    }
};