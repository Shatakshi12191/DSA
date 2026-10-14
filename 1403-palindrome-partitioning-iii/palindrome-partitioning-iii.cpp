class Solution {
public:
    int palindromeCost(int left,int right, string &str){
        int changes = 0;
        while(left < right){
            if(str[left] != str[right]){
                changes++;
            }
            left++;right--;
        }
        return changes;
    }
    int helper(string &s, int pos , int k,vector<vector<int>> &dp){
        int n = s.size();
        if(k == 1){
            return palindromeCost(pos,n-1,s);
        }
        if(dp[pos][k] != -1) return dp[pos][k];
        int minChanges = INT_MAX;
        for(int j = pos; j <= n-k;j++){
            int currentCost = palindromeCost(pos, j, s);
            int remainingCost = helper(s, j + 1, k - 1,dp);
            minChanges = min(minChanges, currentCost + remainingCost);
        }
        return dp[pos][k] = minChanges;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(s,0,k,dp);
    }
}; 