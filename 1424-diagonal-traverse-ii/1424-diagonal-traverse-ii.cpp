#include <algorithm>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int,vector<int>> map;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                map[i+j].push_back(nums[i][j]);
            }
        }
        
        for(auto& i:map){
            for(auto& j:i.second){
                ans.push_back(j);
            }
        }
        
            
        return ans;
    }
};