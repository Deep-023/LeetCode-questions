class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> mp;
        mp[0] = 1;
        long long ans = 0, sum = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                sum++;
            }
            int mod = sum % modulo;
            int need = (mod - k + modulo) % modulo;
            ans += mp[need];
            mp[mod]++;
        }
        return ans;
    }
};
