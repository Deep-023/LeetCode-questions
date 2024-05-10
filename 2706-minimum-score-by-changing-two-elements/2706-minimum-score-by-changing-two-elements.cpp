class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0,n=nums.size();
        ans = abs(nums[2]-nums[n-1]);
        ans = min(ans,abs(nums[0]-nums[n-3]));
        ans = min(ans,abs(nums[1]-nums[n-2]));
        return ans;
    }
};