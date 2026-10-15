class Solution {
public:

    int sumCounts(vector<int>& nums) {
        int distinctCount = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            unordered_set<int>visited;
            for(int j = i ; j < nums.size() ;j++){
                visited.insert(nums[j]);
                int n = visited.size();
                distinctCount += n*n;
            }
        }
        return distinctCount;
    }
};