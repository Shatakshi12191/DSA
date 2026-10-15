class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxGap = INT_MIN;
        if(nums.size() < 2) return 0;
        for(int i = 1 ; i < nums.size() ; i++){
            maxGap = max(maxGap,abs(nums[i] - nums[i-1]));
        }
        return maxGap;
    }
};