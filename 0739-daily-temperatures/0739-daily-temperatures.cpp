class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> st;
        int n = temp.size();
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && temp[st.back()]<=temp[i])
                    st.pop_back();
            
            if(st.empty())
                ans[i] = 0;
            else{
                ans[i] = st.back()-i;
            }
            
            st.push_back(i);
        }  
        
        return ans;
    }
};