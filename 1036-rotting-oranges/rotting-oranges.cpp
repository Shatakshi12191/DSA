class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0,maxTimer = 0;
        int m = grid.size();
        int n = grid[0].size();

        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>> Q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    Q.push({i,j,0});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        while(!Q.empty()){
            vector<int>curr = Q.front();
            Q.pop();
            int r = curr[0];
            int c = curr[1];
            int t = curr[2];
            maxTimer = max(maxTimer,t);
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + d[i][0];
                int nc = c + d[i][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;fresh--;
                    Q.push({nr,nc,t+1});
                }
            }
        }
        return fresh == 0 ? maxTimer : -1;
    }
};