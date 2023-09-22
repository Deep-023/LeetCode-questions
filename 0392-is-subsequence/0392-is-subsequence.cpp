class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        if(n==0)
            return true;
        int j=0;
        for(int i=0;i<t.size();i++){
            if(j<n && s[j]==t[i])
                j++;
        }
        if(j==n)
            return true;
        return false;
    }
};