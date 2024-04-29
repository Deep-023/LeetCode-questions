class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
            ans ^= nums[i];
        
        int res = 0;
        while(ans!=0 || k!=0){
            if((ans&1) != (k&1)){
                res++;
            }
            ans = ans>>1;
            k = k>>1;
        }
        return res;
    }
};