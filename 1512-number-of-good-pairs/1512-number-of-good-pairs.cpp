class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans =0;
        for(auto i:nums){
            m[i]++;
            ans += m[i]-1;
        }
        return ans;
    }
};