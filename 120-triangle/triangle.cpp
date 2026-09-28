class Solution {
public:

    int helper(int i ,int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int m = triangle.size();
        if(i == m-1) return triangle[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int takei = triangle[i][j] + helper(i+1,j,triangle,dp);
        int takej = triangle[i][j] + helper(i+1,j+1,triangle,dp);
        return dp[i][j]=min(takei,takej);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return helper(0,0,triangle,dp);
    }
};