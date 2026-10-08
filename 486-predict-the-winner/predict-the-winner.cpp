class Solution {
public:

    int helper(int i, int j , vector<int> &nums){
        if(i == j) return nums[i];
        int left = nums[i] - helper(i+1,j,nums);
        int right = nums[j] - helper(i,j-1,nums);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int ans = helper(0,n-1,nums);
        if(ans >= 0) return true;
        return false;
    }
};