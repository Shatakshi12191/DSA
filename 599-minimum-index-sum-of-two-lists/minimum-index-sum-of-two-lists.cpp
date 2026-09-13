class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>result;
        int minimum = INT_MAX;
        for(int i = 0 ; i < list1.size() ;i++){
            for(int j = 0 ; j < list2.size() ; j++){
                if(list1[i] == list2[j]){
                int currSum = i+j;
                if(currSum < minimum){
                    result.clear();
                    result.push_back(list1[i]);
                    minimum = currSum;
                }else if(currSum == minimum){
                    result.push_back(list1[i]);
                }
                }
            }
        }
        return result;
    }
};