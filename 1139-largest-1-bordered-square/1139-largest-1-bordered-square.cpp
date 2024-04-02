class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>>top(n,vector<int>(m,0));
        vector<vector<int>>left(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    top[i][j] = i>0 ? top[i-1][j]+1 : 1;
                }else
                    top[i][j] = 0;
            }    
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 && grid[i][j]==1)
                    left[i][j] = 1;
                else if(grid[i][j]==1)
                    left[i][j] = left[i][j-1]+1;
                else
                    left[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(top[i][j] != 0 && left[i][j] != 0){
                    int maxi = min(top[i][j],left[i][j]);
                    
                    while(maxi>0){
                        int l = j-maxi+1;
                        int t = i-maxi+1;
                        if(left[t][j]>=maxi && top[i][l]>=maxi){
                            ans = max(ans,maxi*maxi);
                            break;
                        }
                        maxi--;
                    }
                }
            }
        }
        return ans;
    }
};