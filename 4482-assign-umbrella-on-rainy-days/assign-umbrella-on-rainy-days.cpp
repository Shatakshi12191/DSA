class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int cnt1 = 0, cnt2 = 0;
        int n = rain.size();
        vector<string>ans(n,"None");
        for(int i = 0 ; i < n ; i++){
            bool alice = (i < n-1 && rain[i] == 1 && rain[i+1] == 1);
            bool bob = (rain[i] == 1);
            if(alice && bob){
                if(cnt1 <= cnt2){
                    cnt1++;
                    ans[i] = "Alice";
                }else{
                    ans[i] = "Bob";cnt2++;
                }
            }else if(alice){
                ans[i] = "Alice";
                cnt1++;
            }else if(bob){
                ans[i] = "Bob";
                cnt2++;
            }
        }
        return ans;
    }
};