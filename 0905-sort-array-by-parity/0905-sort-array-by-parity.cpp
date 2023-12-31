class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        for(int k=0;k<n;k++){
            if(nums[k]&1)
                ans[j--] = nums[k];
            else
                ans[i++] = nums[k];
        }
        return ans;
    }
};