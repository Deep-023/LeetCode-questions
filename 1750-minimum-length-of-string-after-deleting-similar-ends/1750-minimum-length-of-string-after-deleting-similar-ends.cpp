class Solution {
public:
    int minimumLength(string s) {
        int i=0,n=s.size();
        int j = n-1;
        
        while(i<j){
            if(s[i]==s[j]){
                while(i<j && s[i]==s[i+1]){
                    i++;
                }
                while(j>i && s[j]==s[j-1]){
                    j--;
                }
            }else{
                break;
            }
            
            i++;
            j--;
        }
        
        return j-i+1 > 0 ? j-i+1 : 0;
    }
};