class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=1,num=0,maxCount=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }else{
                count=1;
            }
            
            if(nums[i]>num){
                num = nums[i];
                maxCount = count;
            }
            if(nums[i]==num && maxCount<count)
                maxCount = count;
        }
        if(nums[nums.size()-1] > num)
            maxCount = 1;
        return maxCount;
    }
};