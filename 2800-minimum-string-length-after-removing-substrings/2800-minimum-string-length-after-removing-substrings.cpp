class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for(auto& c:s){
            if(!stk.empty() && ((c=='B' && stk.top()=='A') || (c=='D' && stk.top()=='C'))){
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.size();
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();