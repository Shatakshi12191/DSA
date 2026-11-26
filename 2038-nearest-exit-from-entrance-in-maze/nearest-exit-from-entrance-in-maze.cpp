class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int x = entrance[0], y = entrance[1];
        int d[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
        queue<vector<int>>Q;
        Q.push({x,y,0});
        maze[x][y] = '+';
        while(!Q.empty()){
            vector<int>curr = Q.front();
            Q.pop();
            int r = curr[0];
            int c = curr[1];
            int dist = curr[2];
            for(int k = 0 ; k < 4;k++){
                int nr = r + d[k][0];
                int nc = c + d[k][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.'){
                    if(nr == 0 || nr == m-1 || nc == 0 || nc == n-1){
                        return dist+1;
                    }
                    maze[nr][nc] = '+';
                    Q.push({nr,nc,dist+1});
                }
            }
        }
        return -1;
    }
};