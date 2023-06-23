class Solution {
public:
    double power(double x, int n){
        int ans;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        
        
        if(n&1){
            x = x*power(x,n-1);
        }
        else
            x = power(x*x,n/2);
        
        return x;
    }
    
    double myPow(double x, int n) {
        double ans = 0;
        if(x==1)
            return 1;
        if(x==-1 && n==INT_MIN)
            return 1;
        
        if(n==INT_MIN)
            return 0;
        if(n>=0)
        ans = power(x,n);
        else
        ans = 1/power(x,abs(n));
        return ans;
    }
};

