class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int dp[26]={0};
        int ans  = 0;
        for(int i=0;i<s.size();i++){
            int mx = 0;
            for(int j=0;j<26;j++){
                if(abs(s[i]-'a'-j)<=k)
                    mx = max(mx,dp[j]);
            }
            dp[s[i]-'a'] = mx+1; 
            ans = max(ans,dp[s[i]-'a']);
        }
        return ans;
    }
};