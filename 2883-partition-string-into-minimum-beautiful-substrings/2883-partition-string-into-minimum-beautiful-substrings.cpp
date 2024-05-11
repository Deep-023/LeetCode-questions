class Solution {
public:
    int dp[16];
    bool isPow(long long a, long long b){
        while(a % b == 0)
            a=a/b;
        if(a == 1)
            return true;
        return false;
    }
    bool check(string& s, int i, int n){
        long long pow = 1;
        long long ans = 0;
        for(int ind = n ;ind>=i;ind--){
            ans += pow*(s[ind]-'0');
            pow = pow<<1;
        }

        if(isPow(ans,5)){
            return true;
        }
        return ans==1;
    }
    int solve(string& s, int idx){
        if(idx>=s.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans = 20;
        for(int i=idx;i<s.size();i++){
            if((i==s.size()-1 || s[i+1]!='0') && check(s,idx,i)){
                //cout<<s.substr(idx,i-idx+1)<<endl;
                ans = min(ans,1+solve(s,i+1));
            }
        }
        return dp[idx]=ans;
    }


    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0')
            return -1;
        memset(dp,-1,sizeof(dp));
        int ans = solve(s,0);
        return ans>15 ? -1 : ans;
    }
};
