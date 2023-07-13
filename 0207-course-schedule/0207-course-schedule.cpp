class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> indegree(n,0);
        int count=0;
        for(int i=0;i<pr.size();i++){
            int u = pr[i][0];
            int v = pr[i][1];
            adj[v].push_back(u);
        }
        
        for(int i=0;i<adj.size();i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(!indegree[i])
                q.push(i);
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;
            for(auto i:adj[top]){
                indegree[i]--;
                if(!indegree[i])
                   q.push(i); 
            }   
        }
        if(count==n)
            return true;
        return false;
    }
};