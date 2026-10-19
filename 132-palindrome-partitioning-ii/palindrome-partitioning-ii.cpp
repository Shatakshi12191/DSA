class Solution {
public:

    int helper(int st, string &s, vector<int> &dp,vector<vector<int>> &palindrome){
        if(st == s.size()) return 0;
        if(dp[st] != -1) return dp[st];
        int ans = INT_MAX;
        for(int end = st; end < s.size() ; end++){
            if(palindrome[st][end]){
                ans = min(ans,1+helper(end+1,s,dp,palindrome));
            }
        }
        return dp[st] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>>palindrome(n,vector<int>(n,0));
        vector<int>dp(n,-1);
        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n-len ; i++){
                int j = i+len-1;
                if(len == 1){
                    palindrome[i][j] = 1;
                }else if(len == 2){
                    if(s[i] == s[j]){
                        palindrome[i][j] = 1;
                    }
                }else{
                    if(s[i] == s[j] && palindrome[i+1][j-1] == 1){
                        palindrome[i][j] = 1;
                    }
                }
            }
        }
        return helper(0,s,dp,palindrome)-1;
    }
};