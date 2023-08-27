class Solution {
public:
    
    bool solve(int k, int ind, vector<int>& stones, int n, int target, unordered_map<int,int>& m, int count, vector<vector<int>>&dp, int ik){
        if(count==target)
            return true;
        if(count+k>target)
            return dp[ind][k]=false;
        
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        
        
        if(m.find(count+k)!=m.end()){
            if(solve(k+1,m[count+k],stones,n,target,m,count+k,dp,k-1))
                return dp[ind][k]=true;
            else if(solve(k,m[count+k],stones,n,target,m,count+k,dp,k-1))
                return dp[ind][k]=true;
            else if( (k-1!=0) && solve(k-1,m[count+k],stones,n,target,m,count+k,dp,k-1))
                return dp[ind][k]=true;
        }
        
        return dp[ind][k]=false;      
        
    }
    
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(10000,-1));
        for(int i=0;i<n;i++){
            m[stones[i]]=i;
        }
        return solve(1,1,stones,n,stones[n-1],m,0,dp,0);
    }
};