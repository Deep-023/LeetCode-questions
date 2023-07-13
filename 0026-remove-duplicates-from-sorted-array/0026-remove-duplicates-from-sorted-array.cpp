class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=1, j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[j]<nums[i]){
                ans++;
                nums[++j]=nums[i];
            }
        }
        return ans;
    }
};