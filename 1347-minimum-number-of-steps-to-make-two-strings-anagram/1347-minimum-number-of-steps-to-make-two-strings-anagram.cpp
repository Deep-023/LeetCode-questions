class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> map(26,0);int a=97;
        
        for(int i=0;i<s.size();i++){
            map[s[i]-a]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(map[t[i]-a] > 0)
                map[t[i]-a]--;
        }
        
        int ans = 0;
        for(int i=0;i<26;i++){
            if(map[i] >= 0)
                ans+= map[i];
        }
        
        return ans;
        
    }
};