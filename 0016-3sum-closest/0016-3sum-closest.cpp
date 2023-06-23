class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int low,high,n=nums.size();
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            low = i+1;
            high = n-1;
            while(high>low){
                int res = nums[i]+nums[low]+nums[high]-target;
                if(res==0)
                    return target;
                if(res<ans && res<0)
                    low++;
                else
                    high--;
                
                if(abs(res)<abs(ans))
                    ans = res;
            }
        }
        return ans+target;
    }
};