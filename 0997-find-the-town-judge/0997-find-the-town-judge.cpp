class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> vis(n+1,0);
        vector<int> vis1(n+1,0);
        for(int i=0;i<trust.size();i++){
            vis[trust[i][1]]++;
            vis1[trust[i][0]]++;
        }
        int ans = -1;
        for(int i=1;i<=n;i++)
            if(vis[i]==n-1 && vis1[i]==0)
                ans=i;
        return ans;
    }
};