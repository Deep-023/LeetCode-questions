class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        int i = find(nums.begin(),nums.end(),target) - nums.begin();
        while(i<n && nums[i]==target){
            ans.push_back(i++);
        }
        return ans;
    }
};