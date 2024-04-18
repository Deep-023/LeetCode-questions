class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> list;
        int n = nums.size();
        for(int i=0;i<n;i++){
            auto itr = lower_bound(list.begin(),list.end(),nums[i]);
            if(itr == list.end())list.push_back(nums[i]);
            else *itr = nums[i];
        }
        return list.size();
    }
};