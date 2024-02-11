class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // check all possible path for each robot ; 
        int m = grid.size() ; 
        int n = grid[0].size() ;

        // if flag = 0 then move the robot 1 else robot 2 ; 
        // return grid[0][0] + grid[0][n-1] + solve(grid, 0, 0, n-1) ; 

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1))) ; 

        return grid[0][0] + grid[0][n-1] + solveMem(grid, 0, 0, n-1, dp) ; 
    }
private:
    
    int solve(vector<vector<int>>& grid, int row, int n1, int n2) {
        if(row == grid.size()-1) {
            return 0 ;
        }

        int m = grid.size() ; 
        int n = grid[0].size() ; 

        vector<int> change = {-1, 0, 1} ; 
        // check all path for robot1 ; 
        int ans = INT_MIN ; 
        for (int i = 0; i < 3; i++) {
            int row1 = row + 1  ; 
            int col1 = n1 + change[i] ; 
            // cout << row1 << " " << col1 << endl ;
            if(col1 >= 0 && col1 < n){
                for (int j = 0; j < 3; j++) {
                    int row2 = row + 1 ; 
                    int col2 = n2 + change[j] ; 

                    // cout << row2 << " " << col2 << endl ;
                    if(col2 > col1 && col2 < n) {
                        ans = max(ans, grid[row1][col1] + grid[row2][col2] + solve(grid, row1, col1, col2)) ; 
                    }
                    
                }
            }
            
        }
        return ans ; 
    }

    int solveMem(vector<vector<int>>& grid, int row, int n1, int n2, vector<vector<vector<int>>>& dp) {
        if(row == grid.size()-1) {
            return 0 ;
        }

        if(dp[row][n1][n2] != -1) {
            return dp[row][n1][n2] ; 
        }

        int m = grid.size() ; 
        int n = grid[0].size() ; 

        vector<int> change = {-1, 0, 1} ; 
        // check all path for robot1 ; 
        int ans = INT_MIN ; 
        for (int i = 0; i < 3; i++) {
            int row1 = row + 1  ; 
            int col1 = n1 + change[i] ; 
            // cout << row1 << " " << col1 << endl ;
            if(col1 >= 0 && col1 < n){
                for (int j = 0; j < 3; j++) {
                    int row2 = row + 1 ; 
                    int col2 = n2 + change[j] ; 

                    // cout << row2 << " " << col2 << endl ;
                    if(col2 > col1 && col2 < n) {
                        ans = max(ans, grid[row1][col1] + grid[row2][col2] + solveMem(grid, row1, col1, col2, dp)) ; 
                    }
                    
                }
            }
            
        }
        return dp[row][n1][n2] = ans ; 
    }

};