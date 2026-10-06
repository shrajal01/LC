class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();

        if(m==0) return;

        int n=matrix[0].size();
        vector<vector<int>>original=matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(original[i][j]==0){
                    for(int x=0;x<n;x++){
                        matrix[i][x]=0;
                    }
                    for(int y=0;y<m;y++){
                        matrix[y][j]=0;
                    }
                }
            }
        }
    }
};