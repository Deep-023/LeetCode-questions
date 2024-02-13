class Solution {
public:
    bool pal(string& ab){
        int i=0;
        int j=ab.size()-1;
        
        while(i<j){
            if(ab[i++]!=ab[j--])
                return false;
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        for(int i=0;i<words.size();i++){
            if(pal(words[i]))
                return words[i];
        }
        
        return "";
    }
};