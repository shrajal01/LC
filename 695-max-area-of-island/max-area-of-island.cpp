class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});

        int area = 1;

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int maxArea=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int currentArea=bfs(i,j,vis,grid);
                    maxArea=max(maxArea,currentArea);
                }
            }
        }
        return maxArea;
    }
};