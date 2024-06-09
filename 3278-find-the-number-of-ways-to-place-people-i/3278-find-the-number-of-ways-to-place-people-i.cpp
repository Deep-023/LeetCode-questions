class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto comp = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(points.begin(), points.end(), comp);
        int ans = 0;
        for(int i = 0; i < points.size(); ++i){
            int cx = points[i][0], cy = points[i][1];
            int k = -1e5;
            for(int j = i+1; j < points.size(); ++j){
                int tx = points[j][0], ty = points[j][1];
                if(ty>cy) continue;
                if(ty>k){
                    k = ty;
                    ans++;
                }
            }
        }
        return ans;
    }
};