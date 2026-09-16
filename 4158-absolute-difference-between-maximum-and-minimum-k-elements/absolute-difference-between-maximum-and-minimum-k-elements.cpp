class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int smallestSum = 0;
        int largestSum = 0;
        for(int i = 0 ; i < k ; i++){
            smallestSum += nums[i];
        }
        for(int i = nums.size()-1 ; i >= 0; i--){
            if(k != 0){
                largestSum += nums[i];
                k--;
            }
        }
        int diff = abs(largestSum - smallestSum);
        return diff;
    }
};