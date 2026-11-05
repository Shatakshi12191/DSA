class Solution {
public:
    
    int helper(vector<int>& nums, int k){
        int left = 0, cnt = 0;
        unordered_map<int,int>mp;
        for(int right = 0 ; right < nums.size() ; right++){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            cnt += (right-left+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums,k) - helper(nums,k-1);
    }
};