class Solution {
public:
    
    vector<int> leftMin(vector<int>& arr, int n){
        stack<int> s;
        vector<int>ans(n,-1);
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            if(!s.empty())
                ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> rightMin(vector<int>& arr, int n){
        stack<int> s;
        vector<int>ans(n,n);
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            if(!s.empty())
                ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int calLargest(vector<int>& histo, int n){
        
        vector<int> left = leftMin(histo,n);
        vector<int> right = rightMin(histo,n);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int num = histo[i];
            ans = max(ans, num*(right[i]-left[i]-1));
        }
        return ans;
    }
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histo(m,0);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0)
                    histo[j] += matrix[i][j];
                else
                    histo[j] = 0;
            }
            vector<int> dummy = histo;
            sort(dummy.begin(),dummy.end());
            ans = max(ans,calLargest(dummy,m));
        }
        
        return ans;
    }
};