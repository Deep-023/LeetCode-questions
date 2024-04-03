class Solution {
public:
    int n,m;
    bool isSafe(int i, int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    vector<vector<int>> dict = {{1,0},{0,1},{-1,0},{0,-1}};
    bool solve(vector<vector<char>>& board, string& word, int idx, int i, int j, vector<vector<int>>&vis){
        vis[i][j] = 1;
        if(idx>=word.size())
            return true;
        
        for(int k=0;k<4;k++){
            int row = i+dict[k][0];
            int col = j+dict[k][1];
            if(isSafe(row,col) && board[row][col]==word[idx] && (!vis[row][col])){
                if(solve(board,word,idx+1,row,col,vis))
                    return true;
            }
        }
        
        vis[i][j] = 0;
        return false;
    }
    
        
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(solve(board,word,1,i,j,vis))
                        return true;
                }
            }
        }
        
        return false;
        
    }
};