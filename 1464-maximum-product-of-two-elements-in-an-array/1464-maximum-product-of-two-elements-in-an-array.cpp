class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = -1 , maxi2 = -1, n=nums.size();
        for(int i=0;i<n;i++){
            if(maxi < nums[i]){
                maxi2 = maxi;
                maxi = nums[i];
            }else if (maxi2 < nums[i]){
                maxi2 = nums[i];
            }
        }
        
        return (maxi-1)*(maxi2-1);
    }
};