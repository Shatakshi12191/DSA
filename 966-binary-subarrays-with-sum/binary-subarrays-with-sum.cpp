class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0, sum = 0,cnt = 0;
        if( k < 0) return 0;
        for(int right = 0 ; right < n ; right++){
            sum += nums[right];
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            cnt += (right-left+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return helper(nums,goal) - helper(nums,goal-1);
    }
};