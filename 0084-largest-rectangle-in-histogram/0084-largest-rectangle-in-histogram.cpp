class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,-1);
        vector<int>right(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!= -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.top();
            s.push(i);
        }
    
        while(s.top()!= -1)
            s.pop();

        for(int i=n-1;i>=0;i--){
            while(s.top()!= -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.top();
            s.push(i);
        }
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            right[i] = right[i] == -1 ? n : right[i]; 
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
    
};