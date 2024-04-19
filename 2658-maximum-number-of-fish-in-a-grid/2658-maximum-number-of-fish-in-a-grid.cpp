class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited){
        
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || visited[i][j]==1 || grid[i][j] == 0)
            return 0;
        
        int ans = grid[i][j];
        
        visited[i][j] = 1;
        
        ans += dfs(grid,i+1,j,visited);
        ans += dfs(grid,i,j+1,visited);
        ans += dfs(grid,i-1,j,visited);
        ans += dfs(grid,i,j-1,visited);
        
       // cout<<ans<<endl;
        return ans;
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    ans = max(ans,dfs(grid,i,j,visited));
                    visited = vector<vector<int>>(n,vector<int>(m,0));
                    //cout<<"________________________"<<endl;
                }
                
            }
        }
        
        return ans;
    }
};