class Solution {
public:
    void partitionHelper(int idx, string s, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (palindrome(s, idx, i) == true) {
                temp.push_back(s.substr(idx, i-idx+1));
                partitionHelper(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    bool palindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;    
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partitionHelper(0, s, temp, ans);
        return ans;
    }
};