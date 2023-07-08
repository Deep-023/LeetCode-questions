class Solution {
public:
    int count = 0;
    vector<int> left, upperDiagonal , lowerDiagonal;
    
    void solve(int col, int n){
        
        if(col>=n){
            count++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(!left[row] && !lowerDiagonal[row+col] && !upperDiagonal[n-1+col-row]){
                left[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row] =1;
                solve(col+1, n);
                left[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row] =0;
            }
        }
    }
    
    int totalNQueens(int n) {
        left.assign(n,0);
        upperDiagonal.assign(2*n-1,0);
        lowerDiagonal.assign(2*n-1,0);
        solve(0,n);
        return count;
    }
};