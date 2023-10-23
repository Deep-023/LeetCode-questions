class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double num = log2(n) / log2(4);
        if(num == (int)num)
            return true;
        return false;
    }
};