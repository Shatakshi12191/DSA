class Solution {
public:

    int helper(vector<int>& coins, vector<vector<int>>& dp, int n, int amount){
        if(amount == 0) return 0;
        if(n == 0) return INT_MAX;
        if(dp[n][amount] != -1) return dp[n][amount];
        int take = INT_MAX;
        int skip = helper(coins,dp,n-1,amount);
        if(coins[n-1] <= amount){
            int result = helper(coins,dp,n,amount-coins[n-1]);
            if(result != INT_MAX){
                take = 1 + result;
            }
        }

        return dp[n][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = helper(coins,dp,n,amount);
        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};