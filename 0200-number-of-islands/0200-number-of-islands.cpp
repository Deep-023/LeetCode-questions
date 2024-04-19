class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited){
        
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]=='0' || visited[i][j]){
            return;
        }
        
        visited[i][j] = 1;
        
        dfs(grid,i+1,j,visited);
        dfs(grid,i,j+1,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j-1,visited);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n1 = grid.size(), n2=grid[0].size();
        vector<vector<int>> visited(n1,vector<int>(n2,0));
        int ans = 0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,visited);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};