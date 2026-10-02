class Solution {
public:
    int helper(int i ,vector<int>& dp, vector<int>& cost){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int one = cost[i] + helper(i+1,dp,cost);
        int two = INT_MAX;
        if(i < cost.size()){
            two = cost[i] + helper(i+2,dp,cost);
        }
        return dp[i] = min(one,two); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(helper(0,dp,cost),helper(1,dp,cost));
    }
};