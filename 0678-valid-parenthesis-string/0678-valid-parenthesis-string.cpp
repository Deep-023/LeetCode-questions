class Solution {
public:
    bool checkValidString(string s) {
        // for this question we will count max open and normal open brackets left;
        int maxb = 0,minb=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                maxb++;
                minb++;
            }else if(s[i]==')'){
                maxb--;
                minb = max(minb-1,0);
            }else{
                minb = max(minb-1,0);
                maxb++;
            }
            if(maxb<0)
                return false;
        }
        
        return minb==0;
    }
};