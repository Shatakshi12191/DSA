class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0,  sum = 0, minW = INT_MAX;
        for(int i = 0; i < n ; i++){
            sum += nums[i];
            while(sum >= target){
                minW = min(minW,i-left+1);
                sum -= nums[left];
                left++;
            }
        }
        if(minW == INT_MAX) return 0;
        return minW;
    }
};