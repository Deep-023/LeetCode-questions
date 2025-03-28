class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    bool isValid(int row, int col, int n, int m){
        return row >= 0 && col >= 0 && row < n && col < m;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int y = grid.size(), z = grid[0].size();
        vector<vector<int>> queriesIndex;
        int n = queries.size();
        for(int i=0;i<n;i++){
            queriesIndex.push_back({queries[i],i});
        }
        sort(queriesIndex.begin(),queriesIndex.end());
        vector<vector<int>> vis(y,vector<int>(z));
        vector<int> ans(n);
        int i = 0, count = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        pq.push({grid[0][0],0,0});
        vis[0][0] = 1;
        while(i<n && !pq.empty()){
            int val = pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            pq.pop();
            while(i<n && val >= queriesIndex[i][0]){
                ans[queriesIndex[i++][1]] = count;
            }
            if(i>=n) break;
            ans[queriesIndex[i][1]] = ++count;
            for(auto & k:dir){
                int row = r + k[0];
                int col = c + k[1];
                if(isValid(row,col,y,z) && !vis[row][col]){
                    vis[row][col] = 1;
                    pq.push({grid[row][col],row,col});
                }
            }
        }
        i++;
        while(i>0 && i<n){
            ans[queriesIndex[i][1]] = ans[queriesIndex[i-1][1]];
            i++;
        }

        return ans;
    }
};