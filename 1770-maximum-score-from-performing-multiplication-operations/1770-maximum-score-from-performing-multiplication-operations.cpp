class Solution {
public:

    int solve(vector<vector<int>> &dp , vector<int>& nums, vector<int>& multipliers , int left , int op){
        if(op == multipliers.size())
            return 0;
        
        if(dp[left][op] != INT_MIN)
            return dp[left][op];

        int right = nums.size() - 1 - (op - left);

        int takeleft = nums[left] * multipliers[op] + solve(dp , nums , multipliers , left+1 , op+1);

        int takeright = nums[right] * multipliers[op] + solve(dp , nums , multipliers , left , op+1);

        return dp[left][op] = max(takeleft, takeright);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>>dp(m+1 , vector<int>(m+1 , INT_MIN));

        return solve(dp , nums , multipliers , 0 , 0);
    }
};