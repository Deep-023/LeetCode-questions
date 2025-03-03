class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> visit(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0,{0,0}});
        vector<int> dirs{0,1,0,-1,0};
        visit[0][0]=0;
        int ans=0,res=INT_MAX;
        while(!pq.empty()) {
            int val = pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
            ans=max(ans, val);
            pq.pop();
            if(x==heights.size()-1 && y==heights[0].size()-1) break;
            for(int i=0;i<4;i++) {
                int nx=x+dirs[i], ny=y+dirs[i+1];
                if(nx>=0 && nx<heights.size() && ny>=0 && ny<heights[0].size()){
                    int currval = max(val,abs(heights[nx][ny] - heights[x][y]));
                    if(visit[nx][ny]>currval) {
                    pq.push({currval, {nx, ny}});
                    visit[nx][ny]=currval;
                }
            }
            }
        }
        return ans;
    }
};