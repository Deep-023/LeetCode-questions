class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int prefixSum=0, availableIdx=-1, res=0;
        m[0]=-1;
        for (int i=0; i<nums.size(); i++){
            prefixSum+=nums[i];
            int remain = prefixSum - target;
            if (m.count(remain) && m[remain]>=availableIdx){
                res++;
                availableIdx=i;
            }
            m[prefixSum]= i;
        }
        return res;
    }
};