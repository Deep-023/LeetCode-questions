class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> n= nums;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                int n1 = (find(n.begin(),n.end(),nums[i]) - n.begin());
                n[n1] = INT_MIN;
                int n2 = (find(n.begin(),n.end(),nums[j]) - n.begin());
                ans.push_back(n1);
                ans.push_back(n2);
                return ans;
            }
            else if(nums[i]+nums[j]<target)
                i++;
            else
                j--;
        }
        return ans;
    }
};