class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=0;i<=3;i++){
            ans = min(ans,abs(nums[i]-nums[n-1-3+i]));
        }
        return ans;
    }
};

//0 1 5 10 14
//0 1 1 4 6 6 6 