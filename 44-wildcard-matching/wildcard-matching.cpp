class Solution {
public:

    int helper(int i , int j , string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(j == 0) return 0;
        if(i == 0){
            while(j > 0){
                if(p[j-1] != '*') return 0;
                j--;
            }
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = helper(i-1,j-1,s,p,dp);
        }else if(p[j-1] == '*'){
            return dp[i][j] = helper(i,j-1,s,p,dp) || helper(i-1,j,s,p,dp);
        }else{
            return dp[i][j] = 0;
        }
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(m,n,s,p,dp);
    }
};