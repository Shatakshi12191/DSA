class Solution {
public:

    int helper(int x , vector<int>& points, vector<int>& dp){
        if(x <= 0) return 0;
        if(dp[x] != -1) return dp[x];
        int pick = points[x] + helper(x-2,points,dp);
        int skip = helper(x-1,points,dp);
        dp[x] = max(pick,skip);
        return dp[x];
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>points(maxi+1,0);
        for(int x : nums){
            points[x] += x;
        }
        vector<int>dp(maxi+1,-1);
        return helper(maxi,points,dp);
    }
};