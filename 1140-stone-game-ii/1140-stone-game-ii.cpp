class Solution {
public:

    int solve(int idx , int M, vector<int> & suffix , vector<vector<int>> &dp){
        int n = suffix.size();
        if(idx >= n )
            return 0;
        
        if(idx + 2*M >= n)
            return suffix[idx];
        
        if(dp[idx][M] != -1)
            return dp[idx][M];

        int ans = 0;

        for(int X = 1 ; X <= 2*M ; X++){
            ans = max(ans , suffix[idx] - solve(idx+X , max(M,X) , suffix , dp));
        }

        return dp[idx][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n);
        suffix[n-1] = piles[n-1];

        for(int i = n-2 ; i >= 0 ; i--){
            suffix[i] = piles[i] + suffix[i+1];
        }

        vector<vector<int>>dp(n , vector<int>(n+1 , -1));

        return solve(0 , 1 , suffix , dp);
    }
};