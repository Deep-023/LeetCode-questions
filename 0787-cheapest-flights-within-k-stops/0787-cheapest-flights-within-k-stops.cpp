class Solution {
public:
    
    int solve(vector<vector<pair<int,int>>>& adj, int i,int dst, int k,vector<vector<int>>& dp){
        
        if(i==dst){
            return 0;
        }
        
        if(k<=0){
            return 1e8;
        }
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int ans = 1e8;
        for(auto& j:adj[i]){
            if(k>0){
                ans = min(ans,j.second + solve(adj,j.first,dst,k-1,dp));
            }
        }
        
        return dp[i][k]=ans;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>dp (n,vector<int>(k+2,-1));
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
         
        int ans = solve(adj,src,dst,k+1,dp);
        return ans >= 1e8 ? -1 : ans;
        
    }
};