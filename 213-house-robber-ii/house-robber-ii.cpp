class Solution {
public:

    int helper(int i, int n,vector<int>& nums, vector<int>& dp){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = max(nums[i]+helper(i+2,n,nums,dp),helper(i+1,n,nums,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        int case1 = helper(0,n-2,nums,dp1);
        vector<int>dp2(n,-1);
        int case2 = helper(1,n-1,nums,dp2);
        return max(case1,case2);
    }
};