class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        int ans=0;
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n-1;i++){
            int num = adj[i].size();
            for(int k=i+1;k<n;k++){
                int count;
                if(find(adj[i].begin(),adj[i].end(),k) != adj[i].end())
                    count = num + adj[k].size() - 1;
                else
                    count = num + adj[k].size();
                ans = max(ans,count);
            }
            
        }
        return ans;
    }
};