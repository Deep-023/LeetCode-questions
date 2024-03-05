class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        
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
            
            if(j==i)
                return 0;
            
            i++;
            j--;
        }
        
        return j-i+1;
    }
};