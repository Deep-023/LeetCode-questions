class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> rows;
        unordered_map<int,int> cols;
        int n = matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }

        for(auto& i:rows){
            for(int j=0;j<m;j++){
                matrix[i.first][j] = 0;
            }
        }

        for(auto& i:cols){
            for(int j=0;j<n;j++){
                matrix[j][i.first] = 0;
            }
        }

        return;
    }
};