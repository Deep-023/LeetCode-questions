class Solution {
public:
    bool doesAliceWin(string s) {
        string temp = "aeiou";
        for(int i=0;i<s.size();i++){
            if(temp.contains(s[i]))
                return true;
        }
        return false;
    }
};