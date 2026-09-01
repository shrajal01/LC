class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>>id(m,vector<int>(n,-1));
        int totalL = 0;

        int sr,sc;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j] == 'L')
                    id[i][j] = totalL++;
                else if(classroom[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
            }
        }
        int fullMask = (1 << totalL) - 1;

        queue<tuple<int,int,int,int,int>> q;

        q.push({sr , sc, energy, 0, 0});

        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                    vector<vector<bool>>(
                        energy + 1,
                        vector<bool>(1 << totalL, false)
                )
            )
        );

        vis[sr][sc][energy][0] = true;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            auto[r,c,e,mask,moves] = q.front();
            q.pop();

            if(mask == fullMask)
                return moves;

            for(int d = 0; d < 4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if(classroom[nr][nc] == 'X')
                    continue;

                int ne = e - 1;

                if(ne < 0)
                    continue;
                
                if(classroom[nr][nc] == 'R')
                    ne = energy;
                
                int nmask = mask;

                if(classroom[nr][nc] == 'L'){
                    int k = id[nr][nc];
                    nmask |= (1<<k);
                }

                if(!vis[nr][nc][ne][nmask]){
                    vis[nr][nc][ne][nmask] = true;

                    q.push({
                        nr,nc,ne,nmask,moves + 1
                    });
                }
            }
        }
        return -1;
    }
};