class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        int digits = to_string(nums[0]).size();

        for (int pos = 0; pos < digits; pos++) {
            vector<int> freq(10, 0);

            for (int i = 0; i < n; i++) {
                int digit = nums[i] % 10;

                ans += i - freq[digit];

                freq[digit]++;
                nums[i] /= 10;   
            }
        }

        return ans;
    }
};