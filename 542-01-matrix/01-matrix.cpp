class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int ones = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>distance(m,vector<int>(n,-1));

        queue<vector<int>>Q;
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    Q.push({i,j,0});
                    distance[i][j] = 0;
                }
            }
        }
        while(!Q.empty()){
            vector<int>curr = Q.front();
            Q.pop();
            int r = curr[0];
            int c = curr[1];
            int t = curr[2];
            for(int i = 0; i < 4 ; i++){
                int nr = r + d[i][0];
                int nc = c + d[i][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && distance[nr][nc] == -1){
                    distance[nr][nc] = t + 1;
                    Q.push({nr,nc,t+1});
                }
            }
        }
        return distance;
    }
};