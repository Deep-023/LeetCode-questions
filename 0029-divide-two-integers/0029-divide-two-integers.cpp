class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        int quotient;
        int sign = (dividend>0)^(divisor>0)?-1:1;
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int res =0;
        while(a>=b){
            int q=0;
            while(a>(b<<(q+1))){
                q++;
            }
            a -= b<<q;
            res += 1<<q;
        }

        if(res > 1<<31 && sign==-1){
            return INT_MIN;
        }
        if(res >= 1<<31 && sign == 1)
            return INT_MAX;
        
        return res*sign;
    }
};