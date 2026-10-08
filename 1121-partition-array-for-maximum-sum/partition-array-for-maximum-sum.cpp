class Solution {
public:
    
    int helper(int i,vector<int> &arr,int k,vector<int> &dp){
        int max_num = -1;
        int len = 0;
        int result = INT_MIN;

        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        for(int j = i ; j < arr.size() && j < i+k ; j++){
            max_num = max(max_num,arr[j]);
            len = j - i + 1;
            int cost = max_num * len + helper(j+1,arr,k,dp);
            result = max(result,cost);
        }
        return dp[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return helper(0,arr,k,dp);
    }
};