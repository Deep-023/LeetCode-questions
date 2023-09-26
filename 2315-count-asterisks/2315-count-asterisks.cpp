class Solution {
public:
    int countAsterisks(string s) {
        int count=0;
        int ans=0;
        for(auto i:s){
            if(i == '|')
                count++;
            if(!(count&1)){
                if(i =='*')
                    ans++;
            }
        }
        return ans;
    }
};