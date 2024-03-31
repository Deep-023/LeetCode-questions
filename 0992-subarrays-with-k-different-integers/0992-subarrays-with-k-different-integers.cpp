class Solution {
public:
    
    /*int solve(vector<int>& nums, int k){
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
    }*/
    
    int subarraysWithKDistinct(vector<int>& nums, int k) { 
        
        int left=0,mx=0,n=nums.size(),ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]++ == 0){
                k--;
                if(k<0){
                    mp[nums[mx++]]--;
                    left = mx;
                }
            }
            if(k<=0){
                while( mx<=i && mp[nums[mx]]> 1 )
                    mp[nums[mx++]]--;
                
                ans += mx-left+1;
            }   
        }
        
        return ans;
    }
};