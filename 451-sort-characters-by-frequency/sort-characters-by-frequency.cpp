class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char,int>>p(mp.begin(),mp.end());
        sort(p.begin(),p.end(),[](auto &a, auto &b){
            return a.second > b.second;
        });
        string ans = "";
        for(auto &v : p){
            for(int i = 0; i < v.second; i++){
                ans += v.first;
            }
        }
        return ans;
    }
};