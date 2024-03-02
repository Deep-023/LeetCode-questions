class Solution {
public:
    int helper(string s, int i, int j) {
  
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
          
        }
        return j - i-1;
      
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0, len = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = helper(s, i, i + 1);
            int len2 = helper(s, i, i);

            len = max(len,max(len1, len2));

            if (len > (end - start)+1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, len);
    }
};