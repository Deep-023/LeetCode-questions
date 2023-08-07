class Solution {
public:
    
    bool isPalindrome(string s){
        int n= s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n= words.size();
        for(int i=0;i<n;i++){
            if(isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};