class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if(ans.size() && abs(ans.back()-s[i])==32){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }             
        }
        
        return ans;
    }
};