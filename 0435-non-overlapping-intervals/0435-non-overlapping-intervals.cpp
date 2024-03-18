class Solution {
public:
    
    static bool comp(const vector<int> a, const vector<int> b){
       return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int ans = 0, mx = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(mx <= intervals[i][0]){
                mx = intervals[i][1];
                continue;
            }else{
                ans++;
            }
        }
        
        return ans;
    }
};