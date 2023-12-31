class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size(),m=t.size();
        
        if(n != m)
            return false;
        
        vector<int> ans(26,0);
        for(int i=0;i<n;i++){
            ans[s[i]-'a']++;
            ans[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(ans[i] != 0)
                return false;
        }
        
        return true;
    }
};