class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int left = 0, maxLen = 0;
        for(int right = 0 ; right < n ; right++){
            if(right > 0 && nums[right] <= nums[right-1]){
                left = right;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};