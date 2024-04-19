class Solution {
public:
    
    void solve(string &s, string temp, int i, int k, vector<string>& ans){
        
        if(i==s.size() && k==0){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        if(k<0 || i>s.size())
            return;
         
        string check;   
        int size = s.size();
        for(int ind = i;ind<min(i+3,size);ind++){
            check.push_back(s[ind]);
            if(stoi(check) < 256){
                check.push_back('.');
                    solve(s,temp+check,ind+1,k-1,ans);
                check.pop_back();
            }
            if(s[i]=='0')
                break;
        }
        
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(s,"",0,4,ans);        
        return ans;
    }
};