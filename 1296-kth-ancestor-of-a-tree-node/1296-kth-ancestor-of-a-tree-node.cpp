class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp = vector<vector<int>>(n+1,vector<int>(20,-1));
        for(int i=0;i<n;i++)
            dp[i][0] = parent[i];
        
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){
                if(dp[i][j-1] != -1)
                    dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=19;i>=0;i--){
            if(k&(1<<i) && node != -1){
                node = dp[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */