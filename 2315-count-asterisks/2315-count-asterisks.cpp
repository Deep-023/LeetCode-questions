class Solution {
public:
    int countAsterisks(string s) {
        int ans=0,count=0;
        for(auto i:s){
            if(i == '|')
                count++;
            if(!(count&1) && i =='*'){
                ans++;
            }
        }
        return ans;
    }
};