class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxElement = INT_MIN;
        if(nums.size() == 0 || nums.size() == 1) return 0;
        for(int i = 0; i < nums.size() ; i++){
            maxElement = max(maxElement,nums[i]);
        }
        int count;
        for(int i = 0 ; i < nums.size(); i++){
            count += abs(maxElement-nums[i]);
        }
        return count;
    }
};