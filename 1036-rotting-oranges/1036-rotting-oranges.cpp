class Solution {
public:
    using pp = tuple<int,int,int>;
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}}; 
    bool isSafe(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0,n=grid.size(),m=grid[0].size(),count=0;
        queue<pp> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j,0});
                else if(grid[i][j]==1) count++;
            }

        while(!q.empty()){
            auto [i,j,cost] = q.front();
            q.pop(); 
            for(int k=0;k<4;k++){
                int newi = i+dir[k][0];
                int newj = j+dir[k][1];

                if(isSafe(newi,newj,n,m) && grid[newi][newj] == 1){
                    grid[newi][newj]=2;
                    q.push({newi,newj,cost+1});
                    count--;
                }
            }
            ans = max(ans,cost);
        }

        if(count != 0) return -1;

        return ans;   
    }
};