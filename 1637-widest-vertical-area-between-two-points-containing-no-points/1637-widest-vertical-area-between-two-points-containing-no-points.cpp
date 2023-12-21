class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        priority_queue<int> ans;
        for(int i=0;i<points.size();i++)
            ans.push(points[i][0]);
        int mx = INT_MIN;
        while(!ans.empty()){
            int num = ans.top();
            ans.pop();
            mx = max(mx, -ans.top()+num);
        }
        return mx;
    }
};