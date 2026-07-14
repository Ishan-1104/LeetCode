class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int small = nums[0];
        int big = nums[n-1];

        return gcd(small , big);
    }
};