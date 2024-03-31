class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int mxCount = 0,mnCount=0;
        int left = 0,mx =0,n=nums.size();
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]>maxK || nums[i]<minK){
                mx = i+1;
                left = i+1;
                mnCount = 0;
                mxCount = 0;
            }
            
            if(nums[i]==maxK)mxCount++;
            if(nums[i]==minK)mnCount++;
            
            if(mxCount>0 && mnCount>0){
                while(mxCount>=1 && mnCount>=1){
                    if((mxCount==1 && maxK==nums[mx]) || (mnCount==1 && minK==nums[mx]))
                        break;
                    if(nums[mx]==maxK)mxCount--;
                    if(nums[mx]==minK)mnCount--;
                    
                    mx++;
                }
                ans += mx-left+1;
            }
        }
        
        return ans;
    }
};