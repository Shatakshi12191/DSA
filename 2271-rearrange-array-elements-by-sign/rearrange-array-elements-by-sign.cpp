class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>negative;
        vector<int>positive;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0){
                negative.push_back(nums[i]);
            }else{
                positive.push_back(nums[i]);
            }
        }
        int j = 0, k = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i%2 == 0 && j < positive.size()){
                nums[i] = positive[j];
                j++;
            }
            if(i%2 != 0 && k < negative.size()){
                nums[i] = negative[k];
                k++;
            }
        }
        return nums;
    }
};