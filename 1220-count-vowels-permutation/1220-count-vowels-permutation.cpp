class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        long long a=1,e=1,i=1,o=1,u=1;
        
        if(n==1)
            return 5;
        
        vector<long long> num(5,0);
        
        for(int q=1;q<n;q++){
            
            num[0] = (e + u + i)%mod;
            num[1] = (a + i)%mod;
            num[2] = (o + e)%mod;
            num[3] = (i)%mod;
            num[4] = (o+i)%mod;
            
            a = num[0];
            e = num[1];
            i = num[2];
            o = num[3];
            u = num[4];
            
        }
        
        return (a+e+i+o+u)%mod;
    }
};