class Solution {
public:
    int binary(int n){
        int ans = 0;
        while(n > 0){
            int rem = 0;
            rem = n % 2;
            n = n / 2;
            ans = ans * 2 + rem;
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> result;

        for(int i = 0 ; i < nums.size() ; i++){
            int reflected = binary(nums[i]);
            result.push_back({reflected, nums[i]});
        }
        sort(result.begin(),result.end());
        vector<int> ans;

        for(auto it : result) {
            ans.push_back(it.second);
        }
        return ans;
    }
};