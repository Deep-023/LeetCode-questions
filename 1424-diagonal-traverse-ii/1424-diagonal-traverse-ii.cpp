#include <algorithm>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int mx =0;
        unordered_map<int,vector<int>> map;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                map[i+j].push_back(nums[i][j]);
                mx = max(mx,i+j);
            }
        }
        
        for(int i=0;i<=mx;i++){
            for(auto& j:map[i])
                ans.push_back(j);
        }
        
            
        return ans;
    }
};