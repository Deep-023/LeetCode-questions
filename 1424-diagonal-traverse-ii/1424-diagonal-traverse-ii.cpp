#include <algorithm>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        /*int mx =0; //normal way
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
        */
        
        //good algorithm using bfs, assume it like a binary tree [0,0] will have [1,0] & [0,1] as left and right child and 
        //same for rest of nodes, if we do bfs in this we will get the answer, but all character will appear 2 times as somebody
        //right node can be somebody left node so we will only consider left node of 0th column
        int n = nums.size();
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int i = q.front().first, j=q.front().second;
            q.pop();
            ans.push_back(nums[i][j]);
            
            if(j==0 && i+1<n)
                q.push({i+1,j});
            if(i<n && j+1<nums[i].size())
                q.push({i,j+1});
            
        }
            
        return ans;
    }
};