class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>n/3)
                s.emplace(nums[i]);
        }
        for(auto i:s)
            ans.push_back(i);
        return ans;
    }
};