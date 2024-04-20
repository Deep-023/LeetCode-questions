class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(),m=land[0].size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int row=i, col=j;
                    for(row;row<n && land[row][j]==1;row++){
                        col=j;
                        while(col<m && land[row][col]==1){
                            land[row][col]=0;
                            col++;
                        }
                    }
                    ans.push_back({i,j,row-1,col-1});
                }
            }
        }

        return ans;
    }
};