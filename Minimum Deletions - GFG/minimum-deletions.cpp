//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int solve(string& S, int st, int ed, vector<vector<int>>& memo){
        if(st==ed)
            return 0;
        
        if(st == ed-1 && S[st]==S[ed])
            return 0;
            
        if(memo[st][ed] != -1)
            return memo[st][ed];
            
        if(S[st] == S[ed]){
            return memo[st][ed] = solve(S,st+1,ed-1,memo);
        }
        
        return memo[st][ed] = 1+min(solve(S,st+1,ed,memo),solve(S,st,ed-1,memo));
    }
  
    int minimumNumberOfDeletions(string S) {
        int n = S.size();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return solve(S,0,S.size()-1,memo);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends