class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int mx = INT_MIN,left=0,n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[left++]]--;
            }
            mx = max(mx,i-left+1);
        }
        return mx;
    }
};