class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>st;
        st.push_back(intervals[0]);
        int n = intervals.size();
        
        for(int i=1;i<n;i++){
            if(!st.empty() && st.back()[1] >= intervals[i][0]){
                vector<int> tp = st.back();
                st.pop_back();
                st.push_back({tp[0],max(tp[1],intervals[i][1])});
            }else{
                st.push_back(intervals[i]);
            }
        }      

        return st;
    }
};