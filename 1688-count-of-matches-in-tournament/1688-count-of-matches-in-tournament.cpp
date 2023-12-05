class Solution {
public:
    int numberOfMatches(int n) {
        
        int ans =0;
        while(n>1){
            if(n&1){
                ans += (n - 1) / 2 + 1;
                n = (n-1)/2;
            }else{
                ans += n/2;
                n = n>>1;
            }
        }
        
        return ans;
        
    }
};