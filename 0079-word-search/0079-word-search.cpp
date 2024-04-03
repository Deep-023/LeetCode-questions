class Solution {
public:
    int n,m;
    bool isSafe(int i, int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
//     bool solveBfs(queue<pair<pair<int,int>,string>>&q,vector<vector<char>>& board, 
//                   string word, int i, int j, int n , int m){
        
//         q.push({{i,j},string(1,word[0])});
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         while(!q.empty()){
//             pair<int,int> p= q.front().first;
//             string ans = q.front().second;
//             int size = ans.size();
//             q.pop();
//             vis[p.first][p.second] = 1;
//             if(ans == word)
//                 return true;
            
//             int i = p.first;
//             int j = p.second;
            
//             if(isSafe(i+1,j,n,m) && board[i+1][j] == word[size] && (!vis[i+1][j])){
//                 ans.push_back(word[size]);
//                 q.push({{i+1,j},ans});
//                 ans.pop_back();
//             }
            
//             if(isSafe(i,j+1,n,m) && board[i][j+1] == word[size] && (!vis[i][j+1])){
//                 ans.push_back(word[size]);
//                 q.push({{i,j+1},ans});
//                 ans.pop_back();
//             }
            
//             if(isSafe(i-1,j,n,m) && board[i-1][j] == word[size] && (!vis[i-1][j])){
//                 ans.push_back(word[size]);
//                 q.push({{i-1,j},ans});
//                 ans.pop_back();
//             }
            
//             if(isSafe(j-1,j,n,m) && board[i][j-1] == word[size] && (!vis[i][j-1])){
//                 ans.push_back(word[size]);
//                 q.push({{i,j-1},ans});
//                 ans.pop_back();
//             }
                 
//         }
        
//         return false;
//     }
    
    vector<vector<int>> dict = {{1,0},{0,1},{-1,0},{0,-1}};
    bool solve(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<int>>&vis){
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
        //queue<pair<pair<int,int>,string>> q;
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