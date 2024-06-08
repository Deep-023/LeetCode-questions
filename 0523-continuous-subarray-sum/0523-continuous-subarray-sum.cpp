class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        long long sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                if(count>=2) return true;
                continue;
            }
            sum += nums[i];
            count = 0;
            if(mp.count(sum%k)){
                if(i-mp[sum%k] >= 2)
                return true;
            }
            else
                mp[sum%k]=i;
        }
        return false;
    }
};