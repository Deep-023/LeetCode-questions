class Solution {
public:
    int MOD = 1e9+7;
    long long dp[10001][15];
    long long fact[10001];

    long long power(int a, int n){
        if(n==1) return a;
        long long result = power(a,n/2);
        result = ((n&1 ? a : 1) * ((result * result) % MOD)) % MOD;
        return result;
    }

    long long factorial(int a){
        if(a==0) return 1;
        if(fact[a] != -1 ) return fact[a];
        return fact[a] = (a*1l*factorial(a-1)) % MOD;
    }

    long long comb(int a, int b){
        return (((factorial(a) * power(factorial(b),MOD-2))%MOD) * power(factorial(a-b),MOD-2)) % MOD;
    }


    int idealArrays(int n, int maxValue) {
        for(int i=0;i<10001;i++){
            fact[i] = -1;
            for(int j=0;j<15;j++){
                dp[i][j] = 0;
            }
        }

        for(int i=1;i<10001;i++){
            dp[i][1] = 1;
            for(int j=2;i*j<=maxValue;j++){
                for(int k=1;k<min(n,14);k++){
                    dp[i*j][k+1] += dp[i][k];
                }
            }
        }

        long long res = 0;
        for(int i=1;i<=maxValue;i++){
            for(int j=1;j<=min(n,14);j++){
                res = (res + ((dp[i][j] * comb(n-1,j-1))%MOD))%MOD;
            }
        }

        return res;

    }
};