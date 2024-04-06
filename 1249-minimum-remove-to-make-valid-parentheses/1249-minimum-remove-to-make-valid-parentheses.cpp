class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int countopen = 0,countclose = 0,n=s.size();
        string ans = "";
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') countopen++;
            else if(s[i]==')') countclose++;
        }
        
        int curropen = 0, currclose = 0;
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i] != ')') ans.push_back(s[i]);
          
            if(s[i]=='(' && countclose>currclose && curropen < countclose-currclose ){
                curropen++;
                ans.push_back(s[i]);
            }
            
            else if(s[i]==')' && curropen>0){
                ans.push_back(s[i]);
                curropen--;
            }
            if(s[i]==')')
                currclose++;
        }
        
        return ans;
    }
};