class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0,left=0,n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]==0 && k==0){
                if(nums[left++]==0)
                    k++;
            }
            if(nums[i]==0)
                k--;
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};