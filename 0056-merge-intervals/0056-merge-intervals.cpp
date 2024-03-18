class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> st;
        st.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            if(st.back()[1]>=intervals[i][0]){
                vector<int> temp = st.back();
                st.pop_back();
                st.push_back({temp[0],max(temp[1],intervals[i][1])});
            }else{
                st.push_back(intervals[i]);
            }
        }
        return st;
    }
};