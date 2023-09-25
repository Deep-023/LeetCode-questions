class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(auto i:s)
            m[i]--;
        for(auto i:t)
            m[i]++;
        for(auto i:m)
            if(i.second==1)
                return i.first;
        
        return -1;
    }
};