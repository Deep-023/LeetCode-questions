class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited){
        
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]=='X' || visited[i][j]){
            return;
        }
        
        visited[i][j] = 1;
        
        dfs(grid,i+1,j,visited);
        dfs(grid,i,j+1,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j-1,visited);
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n1 = board.size(), n2=board[0].size();
        vector<vector<int>> visited(n1,vector<int>(n2,0));
        int ans = 0;
        for(int i=0;i<n1;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(board,i,0,visited);
            }
            if(!visited[i][n2-1] && board[i][n2-1]=='O'){
                dfs(board,i,n2-1,visited);
            }
        }
        
        for(int i=0;i<n2;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(board,0,i,visited);
            }
            if(!visited[n1-1][i] && board[n1-1][i]=='O'){
                dfs(board,n1-1,i,visited);
            }
        }
        
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(board[i][j]=='O' && visited[i][j]==0)
                    board[i][j]='X';
            }
        }
        
        return;
    }
    
};