class Solution {
public:
    
    bool solve(int k, int ind, vector<int>& stones, int target, unordered_map<int,int>& m, int count, vector<vector<int>>&dp){
        if(count==target)
            return true;
        if(count+k>target)
            return dp[ind][k]=false;
        
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        
        count +=k;
        if(m.find(count)!=m.end()){
            if((count+k<=target) && solve(k+1,m[count],stones,target,m,count,dp))
                return true;
            else if(solve(k,m[count],stones,target,m,count,dp))
                return true;
            else if( (k-1!=0) && solve(k-1,m[count],stones,target,m,count,dp))
                return true;
        }
        
        return dp[ind][k]=false;      
        
    }
    
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(1000,-1));
        for(int i=0;i<n;i++){
            m[stones[i]]=i;
        }
        return solve(1,1,stones,stones[n-1],m,0,dp);
    }
};