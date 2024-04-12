class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n);
        
        for(int i=n-1;i>=0;i--){
            right[i] = i==n-1 ? height[i] : max(right[i+1],height[i]);
        }
        
        int ans = 0,left=-1;
        for(int i=0;i<n;i++)
            ans+= (min((left = i==0?height[i]:max(left,height[i])),right[i])-height[i]);
        
        return ans;
    }
};