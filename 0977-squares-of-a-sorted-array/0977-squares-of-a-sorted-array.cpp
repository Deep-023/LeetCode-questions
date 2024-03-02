class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int l=0,r=n-1,k=n-1;
        
        while(l<=r){
            if(abs(nums[l]) > nums[r]){
                ans[k--] = nums[l]*nums[l];
                l++;
            }else{
                ans[k--] = nums[r]*nums[r];
                r--;
            }
        }
        
        return ans;
        
    }
};