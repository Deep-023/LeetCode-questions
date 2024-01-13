class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> map(26,0);int a=97, ans=0;
        
        for(int i=0;i<s.size();i++){
            map[s[i]-a]++;
        }
        
        for(int i=0;i<t.size();i++){
            map[t[i]-a]--;
        }
        
        for(int i=0;i<26;i++){
            if(map[i] >= 0)
                ans+= map[i];
        }
        
        return ans;
        
    }
};