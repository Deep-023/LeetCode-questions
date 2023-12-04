class Solution {
public:
    string largestGoodInteger(string s) {
        int num = -1;
        for(int i=0;i<s.size()-2;i++){
            if(s[i]==s[i+1] && s[i]==s[i+2])
                num = max(num,s[i]-'0');
        }
        
        return num!=-1? string(3,num+'0') : "";
    }
};