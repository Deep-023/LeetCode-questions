class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> m;
        int count=0, n=word.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(word[j] != 'a' && word[j] != 'e' && word[j] != 'i' && word[j] != 'o' && word[j] != 'u')
                    break;
                m[word[j]]++;
                if(m['a']>=1 && m['e']>=1 && m['i']>=1 && m['o']>=1 && m['u']>=1)
                    count++;
            }
            m.clear();
        }
        return count;
    }
};