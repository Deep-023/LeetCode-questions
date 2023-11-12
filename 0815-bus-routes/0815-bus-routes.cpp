class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> route_level;
        int n = routes.size();
        for(int i=0;i<n;i++){
            for(int& j:routes[i])
                route_level[j].push_back(i);  //making an arr where stop levels will be stored
        }
        
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        visited.insert(source);
        q.push({source,0});
        
        while(!q.empty()){
            int stop = q.front().first, level= q.front().second;
            q.pop();
            if(stop==target)
                return level;
            for(int&i: route_level[stop]){
                for(int& j:routes[i]){
                    if(!visited.count(j)){
                        q.push({j,level+1});
                        visited.insert(j);
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};