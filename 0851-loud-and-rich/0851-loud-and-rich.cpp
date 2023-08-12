class Solution {
public:
    void makeList(unordered_map<int, list<int>> &adj, vector<vector<int>>& richer){
        for(auto i : richer){
            adj[i[1]].push_back(i[0]);
        }
    }

    pair<int, int> solve(unordered_map<int, list<int>> &adj, vector<int>& quiet, vector<pair<int, int>> &dp, int node){
        if(dp[node].first != -1) return dp[node];

        pair<int, int> num = {node, quiet[node]};

        for(auto i : adj[node]){
            pair<int, int> temp = solve(adj, quiet, dp, i);

            if(temp.second < num.second){
                num = temp;
            }
        }

        return dp[node] = num;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, list<int>> adj;
        makeList(adj, richer);

        vector<pair<int, int>> dp(n, {-1, -1});
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            pair<int, int> res = solve(adj, quiet, dp, i);
            ans[i] = res.first;
        }

        return ans;
    }
};