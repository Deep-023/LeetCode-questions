class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> cnt(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            cnt[edges[i][0]]++;
            adj[edges[i][1]].push_back(edges[i][0]);
            cnt[edges[i][1]]++;
        }
        int left=n;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(cnt[i]==1)
                q.push(i);
        }
        vector<int> ans;
        while(q.size()){
            int qz = q.size();
            left-=qz; // how many left
            for (int i = 0; i < qz; i++) {
                int v = q.front();
                q.pop();
                if (left==0)//centers are found
                    ans.push_back(v);
            //    cout << v <<": left="<<left<< endl;
                for (int w : adj[v]) {
                    if (--cnt[w] == 1)// remove edge connecting to v
                        q.push(w);
                }
            }
        }
    
        return ans;
    }
};