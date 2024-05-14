class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int n,m;
    bool isSafe(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }

    int dfs(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& vis){
        vis[i][j] = 1;

        int ans = 0;
        for(int k=0;k<4;k++){
            int newi = i+dir[k][0];
            int newj = j+dir[k][1];
            if(isSafe(newi,newj) && !vis[newi][newj] && grid[newi][newj] != 0)
                ans = max(ans,dfs(grid,newi,newj,vis));
        }
        ans += grid[i][j];
        vis[i][j] = 0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size(); 
        vector<vector<int>> vis(n,vector<int>(m));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans = max(ans,dfs(grid,i,j,vis));
                }
            }
        }

        return ans;
    }  
};