class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(map.count(t[i]))
                map[t[i]]--;
        }
        
        int ans = 0;
        for(auto i:map){
            if(i.second >= 0)
                ans+= i.second;
        }
        
        return ans;
        
    }
};