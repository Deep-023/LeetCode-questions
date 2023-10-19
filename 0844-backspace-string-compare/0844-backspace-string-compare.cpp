class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        stack<char> b;
        a.push('/');
        b.push('/');
        
        for(int i=0;i<s.size();i++){
            if(a.top() == '/' && s[i] == '#')
                continue;
            if(s[i] != '#')
                a.push(s[i]);
            else
                a.pop();
        }
        
        for(int i=0;i<t.size();i++){
            if(b.top() == '/' && t[i] == '#')
                continue;
            if(t[i] != '#')
                b.push(t[i]);
            else
                b.pop();
        }
        
        while( !a.empty() && !b.empty()){
            if(a.top() != b.top())
                return false;
            a.pop();
            b.pop();
        }
        
        if(a.empty() && b.empty())
            return true;
        
        return false;
        
    }
};