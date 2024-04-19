class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j] == 0)
            return 0;
        
        int ans = grid[i][j];
        grid[i][j] = 0;
        
        ans += dfs(grid,i+1,j);
        ans += dfs(grid,i,j+1);
        ans += dfs(grid,i-1,j);
        ans += dfs(grid,i,j-1);
        
        return ans;
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        
        return ans;
    }
};