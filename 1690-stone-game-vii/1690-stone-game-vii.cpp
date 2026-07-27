class Solution {
public:

    int solve(int left , int right , vector<int>& stones , vector<int> &prefix , vector<vector<int>> &dp){
        if(left == right)
            return 0;

        if(dp[left][right] != -1)
            return dp[left][right];

        int leftsum = prefix[right + 1] - prefix[left + 1];
        int rightsum = prefix[right] - prefix[left];

        int takeleft = leftsum - solve(left+1 , right , stones , prefix , dp);
        int takeright = rightsum - solve(left , right-1 , stones , prefix , dp);

        return dp[left][right] = max(takeleft , takeright);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));

        vector<int>prefix(n+1 , 0);
        for(int i = 0 ; i < n ; i++){
            prefix[i+1] = prefix[i] + stones[i];
        }

        return solve(0 , n-1 , stones , prefix , dp);
    }
};