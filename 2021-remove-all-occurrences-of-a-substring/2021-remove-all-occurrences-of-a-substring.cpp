class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int n = part.size();
        for(int i=0;i<s.size();i++){
            ans.push_back(s[i]);
            if(s[i]==part[n-1] && ans.size()>=n){
                int j = 0;
                while(j<n && ans[ans.size()-n+j] == part[j]){
                    j++;
                }
                if(j==n){
                    ans = ans.substr(0,ans.size()-n);
                }
            }
        }

        return ans;
    }
};