class Solution {
public:
    
    void rec(vector<string>& ans,unordered_map<int,string> m, string digits,int ind,string answer){
        
        if (ind >= digits.size()){
            ans.push_back(answer);
            return ;
        }
        string h = m[digits[ind]-'0'];
        for(int i=0;i<h.size();i++){
            answer.push_back(h[i]);
            rec(ans,m,digits,ind+1,answer);
            answer.pop_back();
        }
        return;
        
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> m;
        vector<string> answer;
        string ans;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        string str;
        if(!digits.size())
            return answer;
        rec(answer,m,digits,0,str);
        return answer;
        
    }
};