class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, mx = points[0][1];
        for(int i=1;i<points.size();i++){
            if(mx < points[i][0]){
                mx = points[i][1];
                ans++;
            }else
                mx = min(mx,points[i][1]);
        }
        
        return ans;
    }
};