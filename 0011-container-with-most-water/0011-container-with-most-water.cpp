class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int len = right-left;
            int hi = min(height[left],height[right]);
            mx = max(mx, len*hi);
            if(height[left]<height[right])
                left++;
            else if(height[left]>height[right])
                right--;
            else{
                left++;
                right--;
            }
        }
        return mx;
    }
};