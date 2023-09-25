class Solution {
public:
    
    void solve(int n, int left, int right, unordered_set<string>& ans, string output){
        if(left==n && right==n){
            ans.insert(output);
            return;
        }
        
        string temp = output;
        int tempLeft = left;
        
        while(right-tempLeft>0){
            temp.push_back(')');
            solve(n,++tempLeft,right, ans, temp);
        }
        
        temp = output;
        while(right<n){
            temp.push_back('(');
            solve(n,left,++right,ans,temp);
        }
            
    }
    
    vector<string> generateParenthesis(int n) {
        unordered_set<string> ans;
        solve(n,0,0,ans,{});
        vector<string> output;
        for(auto i:ans)
            output.push_back(i);
        return output;
    }
};