class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        for(auto k:nums){
            if(k&1)
                ans[j--] = k;
            else
                ans[i++] = k;
        }
        return ans;
    }
};