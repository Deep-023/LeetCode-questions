class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mp(k);
        mp[0] = 1;
        long long sum = 0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans += mp[((sum%k)+k)%k];
            mp[((sum%k)+k)%k]++;
        }
        return ans;
    }
};