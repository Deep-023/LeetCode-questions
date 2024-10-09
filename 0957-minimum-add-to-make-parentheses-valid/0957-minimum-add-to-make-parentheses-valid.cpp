class Solution {
public:
    int minAddToMakeValid(string s) {
        int need = 0, ans = 0;
        for(auto& c:s){
            if(c=='(') need++;
            else{
                need--;
            }
            if(need<0){
                need=0;
                ans++;
            }
        }
        return need > 0 ? ans+need : ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();