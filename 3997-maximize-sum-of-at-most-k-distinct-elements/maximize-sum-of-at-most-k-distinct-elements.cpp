class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxSum = 0;
        vector<int> ans;
        for(int i = nums.size()-1 ; i >= 0  && k > 0 ; i--){
            if(i == nums.size() - 1 || nums[i] != nums[i + 1]){
                ans.push_back(nums[i]);
                k--;
            }
        }
        return ans;
    }
};