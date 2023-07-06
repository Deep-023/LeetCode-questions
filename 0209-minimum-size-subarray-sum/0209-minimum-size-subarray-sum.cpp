class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count =0, ans=INT_MAX, sum=0, left=0, right=0;
        for(right=0;right<nums.size();right++){
            target -= nums[right];
            while(target<=0 && left<=right){
                    ans = min(ans, right-left+1);
                    target += nums[left];
                    left++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};