class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0,ans = 0,n=nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                sum++;
            else 
                sum--;
            
            if(mp.find(sum) != mp.end()){
                ans = max(ans,i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        
        return ans;
        
    }
};