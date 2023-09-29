class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return true;
        int pos = nums[n-1]-nums[0] > 0 ? 1 : 0;
        if(pos){
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1])
                    return false;
            }
        }else{
            for(int i=0;i<n-1;i++){
                if(nums[i]<nums[i+1])
                    return false;
            }
        }
        return true;
    }
};