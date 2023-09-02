class Solution {
public:
    int solve(string& s, unordered_map<string, int>&mp, vector<int>&dp, int index)
    {
        if (index >= s.size()) return 0;
        if (dp[index] != -1) return dp[index];
        
        string currStr = "";
        int n =  s.size();
        int minExtra = n;
        for (int cutIdx = index; cutIdx < n; cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = solve(s, mp, dp, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        vector<int>dp(s.size(), -1);
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        
        int ans = solve(s, mp, dp, 0);
        return ans;
        
    }
};