class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]+1] = mp[nums[i]]+1;
            mp[nums[i]] = mp[nums[i]-1]+1;
            ans = max({ans,mp[nums[i]],mp[nums[i]+1]});
        }
        
        return ans;
    }
};