class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int idx = find(word.begin(),word.end(),ch)-word.begin();
        if(idx==word.size()) return word;
        for(int i=0;i<=idx/2;i++){
            swap(word[i],word[idx-i]);
        }
        return word;
    }
};