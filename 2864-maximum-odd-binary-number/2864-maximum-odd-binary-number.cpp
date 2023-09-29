class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0,zero=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                zero++;
            else
                one++;
        }
        
        int i=0;
        while(one>0 && i<n){
            if(one>1){
                s[i++]='1';
                one--;
            }
            else if(zero>0){
                s[i++]='0';
                zero--;
            }
            if(zero==0){
                s[i]='1';
                one--;
            }
        }
        return s;
        
    }
};