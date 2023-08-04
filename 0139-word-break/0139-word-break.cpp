/*class Solution {
public:
    bool solve(string s, unordered_set<string> sett, int left, int idx, int n){
        if(left==n)
            return true;
        if(idx >= n)
            return false;
        
        string r = s.substr(left, idx-left+1);
        bool ans1= false;
        
        if(sett.count(r)){
            if(solve(s,sett,idx+1,idx+1,n)){
                return true;
            }
        }
        bool ans2 = solve(s,sett,left,idx+1,n);
        
        if(ans2){
            return true;
        }
        return false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sett(wordDict.begin(),wordDict.end());
        int n= s.size();
        return solve(s, sett, 0, 0,n);
    }
};*/

class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(string s,unordered_set<string>&m){
        if(s.length()==0){
            return true;
        }
        if(dp.find(s)!=dp.end())
        return dp[s];
        string r;
        for(int i=0;i<s.length();i++){
            r.push_back(s[i]);
            if(m.count(r)){
                if(solve(s.substr(i+1),m))
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string>m(wordDict.begin(),wordDict.end());
         return solve(s,m);
    }
};