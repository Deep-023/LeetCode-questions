class Solution {
public:
    string sortVowels(string s) {
        string v;
        unordered_set<char> vowels({'A','E','I','O','U','a','e','i','o','u'});
        
        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i]))
                v.push_back(s[i]);
        }
        
        sort(v.begin(),v.end());
        int j=0;
        
        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i]))
                s[i] = v[j++];
        }
        
        return s;
    }
};