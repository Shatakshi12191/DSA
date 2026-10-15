class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i = 1;
        if(nums.size() == 1) return ans;
        while(i < nums.size()){
            if(nums[i] == nums[i-1]){
                ans.push_back(nums[i]);i++;
            }else{
                i++;
            }
        }
        return ans;
    }
};