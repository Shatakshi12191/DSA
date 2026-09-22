class Solution {
public:

    int helper(int i , int n, vector<vector<int>>& dp){
        if(n == 0) return 0;
        if(i == 0) return 1e9;
        if(dp[i][n] != -1) return dp[i][n];
        if(i*i <= n){
            return dp[i][n] = min(1+helper(i,n-i*i,dp),helper(i-1,n,dp));
        }
        return dp[i][n] = helper(i - 1, n, dp);

    }
    int numSquares(int n) {
        int x = sqrt(n);
        vector<vector<int>>dp(x+1,vector<int>(n+1,-1));
        return helper(x,n,dp);
    }
};