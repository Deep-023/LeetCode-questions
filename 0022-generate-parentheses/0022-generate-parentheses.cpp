class Solution {
public:
    
    void solve(int n, int left, int right, vector<string>& ans, string output){
        if(left==n && right==n){
            ans.push_back(output);
            return;
        }
        
        string temp = output;
        int tempLeft = left;
        
        if(right-tempLeft>0){
            temp.push_back(')');
            solve(n,++tempLeft,right, ans, temp);
        }
        
        temp = output;
        if(right<n){
            temp.push_back('(');
            solve(n,left,++right,ans,temp);
        }
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,ans,{});
        return ans;
    }
};