//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:

    int solve(string& S, int st, int ed, vector<vector<int>>& memo){
        if(st==ed)
            return 1;
        
        if(st == ed-1 && S[st]==S[ed])
            return 2;
            
        if(memo[st][ed] != -1)
            return memo[st][ed];
            
        if(S[st] == S[ed]){
            return memo[st][ed] = 2+solve(S,st+1,ed-1,memo);
        }
        
        return memo[st][ed] =  max(solve(S,st+1,ed,memo),solve(S,st,ed-1,memo));
    }
    
    int longestPalinSubseq(string S) {
        int n = S.size();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return solve(S,0,S.size()-1,memo);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends