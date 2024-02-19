class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        
        double a = log2(n);
        if(a == (int)a)
            return true;
        return false;
    }
};