class Solution {
public:

    int helper(int i , vector<int>& nums,vector<int>& dp){
        int ans = 1;
        if(dp[i] != -1) return dp[i];
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] < nums[j]){
                ans = max(ans,1+helper(j,nums,dp));
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = 0; 
        for(int i = 0 ; i < n; i++){
            ans = max(ans,helper(i,nums,dp));
        }
        return ans;
    }
};