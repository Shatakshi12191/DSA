class Solution {
public:

    bool isPred(string &a, string &b){
        if(b.size() - a.size() != 1) return false;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        return i == a.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size() < b.size();
        });
        int n = words.size();
        int maxLen = 1;
        vector<int>dp(n,1);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(isPred(words[j],words[i])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            maxLen = max(dp[i],maxLen);
        }
        return maxLen;
    }
};