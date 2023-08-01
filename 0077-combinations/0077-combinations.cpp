class Solution {
public:
    
    void solve(int n, int k, int ind, vector<vector<int>>& ans, vector<int>& output){
        if(k==0){
            ans.push_back(output);
            return;
        }
        
        for(int i=ind;i<=n;i++){
            output.push_back(i);
            solve(n,k-1,i+1,ans,output);
            output.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(n,k,1,ans, output);
        return ans;
    }
};