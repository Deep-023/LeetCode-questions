class Solution {
public:
    int n,m;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isSafe(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    bool dfs(vector<vector<int>> &heights, int i, int j, int& diff, vector<vector<bool>> &vis){
        if(i==n-1 && j==m-1)
            return true;
        
        vis[i][j] = 1;
        
        for(int k=0;k<4;k++){
            int newi = i+dir[k][0];
            int newj = j+dir[k][1];
            
            if(isSafe(newi,newj) && vis[newi][newj]==0){
                if((abs(heights[i][j] - heights[newi][newj]) <= diff) && dfs(heights,newi,newj,diff,vis)){
                    vis[i][j] = 0;
                    return true;
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = 1e7;
        n = heights.size(); m=heights[0].size();
        int ans;
        while(low<=high){
            int mid = low+(high-low)/2;
            vector<vector<bool>> vis(n,vector<bool>(m));
            if(dfs(heights,0,0,mid,vis)==true){
                ans = mid;
                if(low==high) break;
                high = mid-1;
            }else{
                if(low==high) break;
                low = mid+1;
            }
        }
        
        return ans;
    }
};