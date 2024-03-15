class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>sum(n);
        sum[0]=1;
        for(int i=1;i<nums.size();i++)
            sum[i]= sum[i-1]*nums[i-1];
        int s = 1;
        for(int i=n-1;i>=0;i--){
            sum[i] *= s;
            s*= nums[i];
        }
        
        return sum;
    }
};