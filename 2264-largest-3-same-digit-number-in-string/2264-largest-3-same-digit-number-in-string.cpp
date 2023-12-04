class Solution {
public:
    string largestGoodInteger(string s) {
        int num = -1;
        for(int i=0;i<s.size()-2;i++){
            if(s[i]==s[i+1] && s[i]==s[i+2])
                num = max(num,s[i]-'0');
        }
        
        if(num==-1)
            return "";
        string st;
        st.push_back(num+'0');
        st.push_back(num+'0');
        st.push_back(num+'0');
        return st;
    }
};