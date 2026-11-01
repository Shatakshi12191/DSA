class Solution {
public:
  
    int helper(int i, int k , vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        if(k == 1){
            int sum = 0;
            for(int t = i ; t < n;t++){
                sum += nums[t];
            }
            return sum;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int currSum = 0;
        int result = INT_MAX;
        for(int j = i ; j <= n-k;j++){
            currSum = currSum + nums[j];
            int remainingSum = helper(j+1,k-1,nums,dp);
            int largeSum = max(currSum,remainingSum);
            result = min(result,largeSum);
        }
        return dp[i][k] = result;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(0,k,nums,dp);
    }
};