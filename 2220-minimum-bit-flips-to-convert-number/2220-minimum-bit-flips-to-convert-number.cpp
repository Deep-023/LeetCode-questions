class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start, b = goal;
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