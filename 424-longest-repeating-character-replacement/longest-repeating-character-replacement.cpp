class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int left = 0, maxLen = 0,maxFreq = 0;
        int replacements = 0;
        for(int right = 0 ; right < n ; right++){
            mp[s[right]]++;
            maxFreq = max(maxFreq,mp[s[right]]);

            replacements = (right-left+1) - maxFreq;
            while(replacements > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
                replacements = (right-left+1) - maxFreq;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};