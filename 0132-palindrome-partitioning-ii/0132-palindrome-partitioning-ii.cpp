class Solution {
public:
    
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    
    int solve(string& s,int idx,int n, vector<int>& m){
        
        if(idx+1==n || isPalindrome(s,idx,n-1)){
            return 1;
        }
        
        if(m[idx] !=-1 )
            return m[idx];
        
        
        int ans=INT_MAX;
        for(int i=n-1;i>=idx;i--){
            if(isPalindrome(s,idx,i)){
                int steps = 1+solve(s,i+1,n,m);
                ans=min(ans, steps);  
            }
        }
        return m[idx]=ans;
    }
    
    int minCut(string s) {
        int n= s.size();
        vector<int> m(n,-1);
        return solve(s,0,n,m)-1;
    }
};