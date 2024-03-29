class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int mx = *max_element(nums.begin(),nums.end());
        int n = nums.size(),count = 0,left=0;
        long long ans = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==mx)
                count++;
            while(count>=k){
                if(nums[left++]==mx)
                    count--;
                ans += (n-i);
            }
        }
        
        return ans;
    }
};