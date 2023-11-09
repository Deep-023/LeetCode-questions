class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        int count =1,count2=1;
        for(int i=1;i<s.size();i++){
            count = (count+1)%mod;
            if(s[i]==s[i-1]){
                count = (count + count2++)%mod ;
                count2 %= mod;
            }
            else
                count2=1;
        }
        return count;
    }
};