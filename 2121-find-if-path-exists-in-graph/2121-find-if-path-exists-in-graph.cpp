class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
            
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n,0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto& i:adj[top]){
                if(i==destination)  return true;
                if(visited[i] != 1){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        return false;
    }
};