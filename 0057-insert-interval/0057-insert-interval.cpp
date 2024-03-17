class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        stack<vector<int>> st;
        int n = intervals.size();
        bool flag = true;
        
        if(n==0)
            return {newInterval};
        
        for(int i=0;i<n;i++){
            if(flag && newInterval[0]<=intervals[i][0]){
                if(st.empty() || (st.top()[1]<newInterval[0])){
                    st.push(newInterval);
                }else{
                    vector<int> tp = st.top();
                    st.pop();
                    st.push({min(tp[0],newInterval[0]),max(tp[1],newInterval[1])});
                }
                flag = false;
            }
                if(st.empty() || (st.top()[1]<intervals[i][0])){
                    st.push(intervals[i]);
                }else{
                    vector<int> tp = st.top();
                    st.pop();
                    st.push({min(tp[0],intervals[i][0]),max(tp[1],intervals[i][1])});
                }
        }
        
        if(flag){
            if(st.top()[1]>=newInterval[0]){
                vector<int> tp = st.top();
                st.pop();
                st.push({min(tp[0],newInterval[0]),max(tp[1],newInterval[1])});
            }
            else
                st.push(newInterval);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};