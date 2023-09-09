class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        
        for(auto i:nums1){
            m1[i]=1;
        }
        for(auto i:nums2){
            m2[i]=1;
        }
        vector<vector<int>> ans(2);
        for(auto i:m1){
            if(i.second==1 && !m2.count(i.first))
                ans[0].push_back(i.first);
        }
        for(auto i:m2 ){
            if(i.second==1 && !m1.count(i.first))
                ans[1].push_back(i.first);
        }
        return ans;
        
    }
};