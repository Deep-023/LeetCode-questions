class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = 0;
                if(grid[i][j]==1){
                    for(int k=i+1;k<n;k++){
                        if(grid[k][j]==1){
                                temp=1;
                            if(!visited[k][j]){
                                count++;
                                visited[k][j] = 1;
                            } 
                        }
                    }
                    for(int k=j+1;k<m;k++){
                        if(grid[i][k]==1){
                                temp = 1;
                            if(!visited[i][k]){
                                count++;
                                visited[i][k]=1;
                            }
                        }
                    }
                    if(temp == 1 && visited[i][j] == 0)
                        count++;
                }
                visited[i][j]=1;
            }
        }
        return count;
    }
};