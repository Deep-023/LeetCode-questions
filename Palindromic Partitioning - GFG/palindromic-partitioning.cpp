//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool check_pal(string& str, int start, int end){
        while(start<=end){
            if(str[start++] != str[end--])
                return false;
        }
        return true;
    }
    
    int palindrome(string& str, int parts, int start, int end, vector<int>& dp){
        
        if(start>=str.size() || start > end){
            return 0;
        }
        
        if(dp[start] != -1)
            return dp[start];
        
        int ans = INT_MAX;
        for(int i=end; i>=start; i--){
            if(check_pal(str,start,i)){
                ans= min(ans,1+palindrome(str,parts+1,i+1,end,dp));
            }
        }
        return dp[start]=ans;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n,-1);
        return palindrome(str,0,0,n,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends