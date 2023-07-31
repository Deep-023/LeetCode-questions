class Solution {
public:
    int solve(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
    int ans=0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + (2*(int)X[i-1]);
                ans= max(ans,L[i][j]);
            }
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
     int index = L[m][n];
    return ans;
}
    
    int minimumDeleteSum(string s1, string s2) {
        int n1= s1.size();
        int n2= s2.size();
        int sum=0;
        for(int i=0;i<s1.size();i++){
            sum+= (int)s1[i];
        }
        for(int i=0;i<s2.size();i++){
            sum += (int)s2[i];
        }
        
        int lcs = solve(s1,s2,n1,n2);
        sum -= lcs;
        
        
        return sum;
    }
};