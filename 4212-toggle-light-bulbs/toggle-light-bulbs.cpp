class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < bulbs.size();i++){
            mp[bulbs[i]]++;
        }
        for(auto it : mp){
            if(it.second % 2 != 0){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};