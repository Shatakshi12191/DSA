class Solution {
public:

    int bits(int i,vector<int>& dp){
        int rem = 0;
        int count = 0;
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        while(i > 0){
        rem = i % 2;
        i = i/2;
        if(rem == 1){
            count++;
        }
        }
        return dp[i] = count;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        vector<int>dp(n+1,-1);
        for(int i = 0; i <= n ; i++){
            ans.push_back(bits(i,dp));
        }
        return ans;
    }
};