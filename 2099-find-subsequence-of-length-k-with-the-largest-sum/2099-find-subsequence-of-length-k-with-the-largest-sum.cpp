class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>dub(nums);
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        vector<int> ans;
        int n = nums.size();
        for(int i=n-k;i<n;i++)
            m[nums[i]]++;
        for(int i=0;i<n;i++){
            if(m[dub[i]]>0){
                m[dub[i]]--;
                ans.push_back(dub[i]);
            }
        }
        return ans;
    }
};