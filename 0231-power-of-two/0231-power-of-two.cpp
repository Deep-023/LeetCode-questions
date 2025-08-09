class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n<= 0 ) return 0;
        double val = log2(n);
        if(val == (int)val) return 1;
        return 0;
    }
};