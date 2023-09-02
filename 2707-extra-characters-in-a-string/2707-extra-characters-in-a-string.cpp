class Solution {
public:
    int solve(string& s, unordered_map<string, int>&mp, vector<int>&dp, int index, int&n)
    {
        if (index >= n) return 0;
        if (dp[index] != -1) return dp[index];
        
        string currStr = "";
        int minExtra = n;
        for (int cutIdx = index; cutIdx < n; cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = solve(s, mp, dp, cutIdx + 1, n);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        int n = s.size();
        vector<int>dp(n, -1);
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        
        int ans = solve(s, mp, dp, 0,n);
        return ans;
        
    }
};