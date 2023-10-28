class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        long long a=1,e=1,i=1,o=1,u=1;
        if(n==1)
            return 5;
        
        vector<long long> num(5,0);
        
        for(int q=1;q<n;q++){
            
            a *= 1;
            e *= 2;
            i *= 4;
            o *= 2;
            u *= 1;
     
            num[0] = (e/2 + u + i/4)%mod;
            num[1] = (a + i/4)%mod;
            num[2] = (o/2 + e/2)%mod;
            num[3] = (i/4)%mod;
            num[4] = (o/2+i/4)%mod;
            
            a = num[0];
            e = num[1];
            i = num[2];
            o = num[3];
            u = num[4];
            
        }
        
        return (a+e+i+o+u)%mod;
    }
};