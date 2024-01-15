class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> map;
        vector<vector<int>> ans(2);
        int n = matches.size();
        
        
        for(int i=0;i<n;i++){
            if(map[matches[i][0]] == 0){
                map[matches[i][0]] = 3;
            }
            
            if(map[matches[i][1]] == 3 || map[matches[i][1]] == 0)
                map[matches[i][1]] = 2;
            
            else if(map[matches[i][1]] == 2){
                map[matches[i][1]] = 1;
            }
        }
        
        for(auto i:map){
            if(i.second == 3)
                ans[0].push_back(i.first);
            if(i.second == 2)
                ans[1].push_back(i.first);
        }
       
        
        return ans;
        
    }
};