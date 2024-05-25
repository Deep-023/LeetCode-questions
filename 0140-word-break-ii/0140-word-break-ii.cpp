class Solution {
public:
    vector<string> ans;
    unordered_set<string> check;
    void solve(int i, int n, string& s, string& temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        
        string curr;
        for(int idx = i; idx<n; idx++){
            curr.push_back(s[idx]);
            if(check.count(curr)==1){
                //cout<<curr<<endl;
                int size = temp.size();
                if(size != 0) temp.push_back(' ');
                temp += curr;
                solve(idx+1,n,s,temp);
                temp = temp.substr(0,size);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        check.insert(wordDict.begin(),wordDict.end());
        string temp;
        solve(0,s.size(),s,temp);
        return ans;
    }
};