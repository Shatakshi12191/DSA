class Solution {
public:
    int canPlace(vector<int>& flowerbed , int i){
        if(i >= flowerbed.size()) return 0;
        if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0)&&(i == flowerbed.size()-1 || flowerbed[i+1] == 0)){
            flowerbed[i] = 1;
            return 1 + canPlace(flowerbed,i+2);
        }
        return canPlace(flowerbed,i+1);
        
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        return canPlace(flowerbed,0) >= n;
    }
};