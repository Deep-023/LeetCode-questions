#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0;
        ll maxNegative=LONG_MIN, count=0, minPos=LONG_MAX;
        for(int i =0;i<nums.size();i++){
            ll num = nums[i];
            ll xorNum = num^k;
            ll diff = xorNum - num;
            ans += num;
            if(diff>0){
                count++;
                minPos = min(minPos , diff);
                ans += diff;
            }else if(diff<0){
                maxNegative = max(maxNegative, diff);
            }
        }
        if(count%2==0)
            return ans;

        return max(ans-minPos, ans+maxNegative);
    }
};