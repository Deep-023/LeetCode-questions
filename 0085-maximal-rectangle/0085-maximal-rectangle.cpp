class Solution {
public:
    
    int largestHisto(vector<int>& mat){
        int n = mat.size();
        vector<int> right(n); vector<int> left(n);
        stack<int> st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && mat[i]<=mat[st.top()])
                st.pop();
            right[i] = st.top();
            st.push(i);
        }
        
        while(st.top() != -1)
                st.pop();
        
        for(int i=0;i<n;i++){
            while(st.top() != -1 && mat[i]<=mat[st.top()])
                st.pop();
            left[i] = st.top();
            st.push(i);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(right[i]==-1) right[i]=n;
            ans = max(ans,mat[i]*(right[i]-left[i]-1));
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<int> mat(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[j] = matrix[i][j]=='0' ? 0 : mat[j]+1;    
            }
            ans = max(ans,largestHisto(mat));
        }
        return ans;
    }
    
    /*int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>> preSum(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]=='1')
                    preSum[i][j] = 1 + (j>0 ? preSum[i][j-1] : 0);
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(preSum[i][j] > 0){
                    int mn = INT_MAX;
                    for(int k=i;k<n;k++){
                        if(preSum[k][j]==0)
                            break;
                        mn = min(mn,preSum[k][j]);
                        ans = max(ans,mn*(k-i+1));
                    }
                }
            }
        }
        
        return ans;
        
        
    }*/
};