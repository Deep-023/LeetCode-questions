class Solution {
public:
    set<vector<string>>ans;
    
     bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    
    void solve(string& s,int idx,int n, vector<string>& output){
        if(n==idx+1){
            output.push_back(string (1, s[n-1]));
            ans.insert(output);
            output.pop_back();
            return;
        }
        string r;
        for(int i=idx;i<n;i++){
            r.push_back(s[i]);
            if(isPalindrome(s,idx,i)){
                output.push_back(r);
                if(isPalindrome(s,i+1,n-1)){
                    string r = s.substr(i+1, n-i+1);
                    if(r!=""){
                    output.push_back(r);
                    ans.insert(output);
                    output.pop_back(); 
                    }
                }
                solve(s,i+1,n,output);
                output.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> output;
        int n = s.size();
        solve(s,0,n,output);
        if(isPalindrome(s,0,n-1)){
            output.push_back(s);
            ans.insert(output);
            output.pop_back();
        }
        vector<vector<string>> anss;
        for(auto i:ans){
            anss.push_back(i);
        }
        return anss;
    }
};