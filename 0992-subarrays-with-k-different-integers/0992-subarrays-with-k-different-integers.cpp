class Solution {
public:
    
    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int n=nums.size(),left=0,ans = 0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]++ == 0)
                k--;
            while(k<0){
                if(--mp[nums[left++]] == 0)
                    k++;
            }
            
            ans += i-left+1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {          
        return solve(nums,k)-solve(nums,k-1);
    }
};