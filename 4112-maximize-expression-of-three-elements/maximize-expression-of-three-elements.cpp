class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maximum = INT_MIN;
        for(int i = 0 ; i < nums.size();i++){
            for(int j = 0 ; j < nums.size() ; j++){
                for(int k = 0 ; k < nums.size(); k++){
                    if(i != j && j != k && i != k){
                        maximum = max(maximum,(nums[i]+nums[j]-nums[k]));
                    }
                }
            }
        }
        return maximum;
    }
};