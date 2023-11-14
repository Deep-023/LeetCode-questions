class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> left(26,n);
        vector<int> right(26,-1);
        
        for(int i=0;i<n;i++){
            right[s[i]-'a'] = i;
            left[s[i]-'a'] = min(left[s[i]-'a'],i);
        }
        
        int ans = 0;
        for(int i=0;i<26;i++){
            if(left[i]<right[i]){
                unordered_set<int> sett(s.begin()+left[i]+1,s.begin()+right[i]);
                ans+= sett.size();
            }
        }
        return ans;
    }
};