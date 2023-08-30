class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n= nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                count+= nums[i]-nums[i+1]+1;
                nums[i+1]= nums[i]+1;
            }
        }
        return count;
    }
};