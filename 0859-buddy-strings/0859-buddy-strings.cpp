class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if(n != goal.size())
            return false;
        
         if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }
        string s1,s2;
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i] != goal[i]){
                count++;
                s1.push_back(s[i]);
                s2.push_back(goal[i]);
                if(count>2)
                    return false;
            }
        }
        if(count == 2 && (s1[0]==s2[1] && s1[1]==s2[0]) )
            return true;
            
        return false;
    }
};