class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>st;
        st.push(intervals[0]);
        int n = intervals.size();
        
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()[1] >= intervals[i][0]){
                vector<int> tp = st.top();
                st.pop();
                st.push({tp[0],max(tp[1],intervals[i][1])});
            }else{
                st.push(intervals[i]);
            }
        }      
        
        intervals.clear();
        while(!st.empty()){
            intervals.push_back(st.top());
            st.pop();
        }
        
        reverse(intervals.begin(),intervals.end());
        return intervals;
    }
};