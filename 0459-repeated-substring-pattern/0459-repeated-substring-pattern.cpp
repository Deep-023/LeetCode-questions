class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                string repeated = "";
                string sb = s.substr(0, i);
                for (int j = 0; j < n / i; j++) {
                    repeated += sb;
                }
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }
};