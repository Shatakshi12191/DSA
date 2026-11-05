class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long currSum = 0, left = 0, count = 0;
        for(int right = 0; right < n; right++){
            currSum += nums[right];
            long long len = right-left+1;
            long long score = currSum * len;
            while(score >= k){
                currSum -= nums[left];
                left++;
                score = currSum*(right-left+1);
            }
            count += (right-left+1);
        }
        return count;
    }
};