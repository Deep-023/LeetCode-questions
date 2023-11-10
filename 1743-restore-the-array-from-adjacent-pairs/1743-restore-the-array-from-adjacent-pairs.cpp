class Solution {
public:
    
    void solve(unordered_map<int,vector<int>>& graph,  unordered_map<int,int>&visited, vector<int>&ans, int node)     {
        if(visited[node])
            return ;
        
        ans.push_back(node);
        visited[node]++;
        for(int i=0;i<graph[node].size();i++){
            solve(graph,visited,ans,graph[node][i]);
        }
    } 
    
    vector<int> restoreArray(vector<vector<int>>& ap) {
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<ap.size();i++){
            graph[ap[i][0]].push_back(ap[i][1]);
            graph[ap[i][1]].push_back(ap[i][0]);
        };
        
        int start ;
        for(auto i:graph){
            if(i.second.size()==1){
                start = i.first;
                break;
            }
        }
        
        vector<int> ans;
        unordered_map<int,int> visited;
        solve(graph,visited,ans,start);
        return ans;
    }
};