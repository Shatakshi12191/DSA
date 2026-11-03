class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k-1){
                if(dq.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(nums[dq.front()]);
                }
            }
        }
        return ans;
    }
};