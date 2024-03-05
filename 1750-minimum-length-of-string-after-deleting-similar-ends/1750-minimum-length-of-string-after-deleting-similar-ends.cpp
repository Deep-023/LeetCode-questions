class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        
        while(i<j && s[i]==s[j]){
            char a = s[i];
            while(i<=j && s[i]==a){
                i++;
            }
            while(i<=j && s[j]==a){
                j--;
            }
        }
        
        return j-i+1 > 0 ? j-i+1 : 0;
    }
};