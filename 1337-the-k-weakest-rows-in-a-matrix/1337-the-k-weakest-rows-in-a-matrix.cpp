class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prior;
        int m = mat.size(), n=mat[0].size();
        for(int i =0 ;i<m;i++){
            int count =0;
            for(int j=0;j<n;j++)
                if(mat[i][j])
                    count++;
            prior.push({count,i});
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(prior.top().second);
            prior.pop();
        }
        
        return ans;
    }
};