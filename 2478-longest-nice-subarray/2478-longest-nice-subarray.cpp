class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> arr(32,-1);
        int ans = 1,mx = -1;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){
                    if(arr[j] != -1 && arr[j]>=mx) mx = max(mx,arr[j]);
                    arr[j] = i;
                }
            }
            ans = max(ans,i-mx);
        }

        return ans;
    }
};