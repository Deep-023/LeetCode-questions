class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long ans = 0;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) { //increments length on power of 2
                len++;
            }
            ans = ((ans << len)%mod + i) % mod;
        }
        return ans;
    }
};