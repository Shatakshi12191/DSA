class Solution {
public:

    int helper(vector<int>& nums,vector<int>& dp, int i, int n){
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        for(int k = 1 ; k <= nums[i] ; k++){
            if(helper(nums,dp,i+k,n) == 1){
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,dp,0,n-1);
    }
};