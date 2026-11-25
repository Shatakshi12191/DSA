class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>>Q;
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if(i == 0 || j == 0|| i == m-1 || j == n-1){
                    if(grid[i][j] == 1){
                        Q.push({i,j});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        while(!Q.empty()){
            vector<int>curr = Q.front();
            Q.pop();
            int x = curr[0];
            int y = curr[1];
            for(int k = 0 ; k < 4; k++){
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 0;
                    Q.push({nx,ny});
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};