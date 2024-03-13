class Solution {
public:
    int pivotInteger(int n) {
        
        if(n==1)
            return 1;
        
        for(int i=1;i<n;i++){
            int ans = (n-i+1)*(n-i+2) + (2*(i-1)*(n-i+1)) - (i*(i+1));
            if(ans == 0)
                return i;
        }
        
        return -1;
    }
};