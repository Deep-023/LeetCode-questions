class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mn = 0, ans = 0, sum = 0, mx=0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ans = max(ans,abs(sum - mn));
            ans = max(ans,abs(sum - mx));
            mx = max(mx,sum);
            mn = min(mn,sum);
        }

        return ans;
    }
};