class Solution {
public:
    int minBitFlips(int a, int b) {
        int ans = 0;
        while(a>0 || b>0){
            if((a&1)!=(b&1)){
                ans++;
            }
            a=a>>1;
            b=b>>1;
        }
        
        return ans;
    }
};