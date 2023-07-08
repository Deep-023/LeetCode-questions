class Solution {
public:
    
    void pushSol(vector<vector<int>>board,vector<vector<string>>& ans, int n){
        vector<string> a;
           for(int i=0;i<n;i++){
               string s;
               for(int j=0;j<n;j++){
                   if(board[i][j]==1)
                       s.push_back('Q');
                   else
                       s.push_back('.');
               }
               a.push_back(s);
           } 
        ans.push_back(a);
    }
    
    bool isSafe(vector<vector<int>>board, int row, int col){
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
        if (board[i][j])
            return false;
 
    return true;
    }
    
    void solveQueen(vector<vector<int>>board, int col, vector<vector<string>>& ans, int n){
        if(col>=n){
            pushSol(board,ans,n);
            return;
        }
    
        for(int i=0;i<n;i++){
            if(isSafe(board,i,col)){
                board[i][col] = 1;
                solveQueen(board,col+1,ans,n);
                board[i][col]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int> (n,0));
        vector<vector<string>> ans;
        solveQueen(board,0,ans,n);
        return ans;
    }
};