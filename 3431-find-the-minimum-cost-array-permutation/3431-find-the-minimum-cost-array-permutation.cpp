class Solution {
public:
    int n,first;
    int dp[1<<15][15];
    int recSolve(int bitmask,vector<int>& nums, int last){
        if(bitmask == (1<<n)-1)
            return abs(last-nums[first]);
        
        if(dp[bitmask][last]!=-1)
            return dp[bitmask][last];
        
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if((bitmask&(1<<i))==0){
                ans = min(ans, abs(last-nums[i]) + recSolve((bitmask|(1<<i)),nums,i));
            }
        }
        return dp[bitmask][last] = ans;
    }

    vector<int> genStr(int first,vector<int>& nums){
        vector<int> ans;
        ans.push_back(first);
        int bitmask = (1<<first);
        int last = first;
        while(bitmask != (1<<n)-1){
            int ind = n-1, val = INT_MAX;
            for(int i=n-1;i>=0;i--){
                if((bitmask&(1<<i))==0){
                    if(dp[(bitmask|(1<<i))][i] + abs(last-nums[i]) <= val){
                        val = dp[(bitmask|(1<<i))][i] + abs(last-nums[i]);
                        ind = i;
                    }
                }
            }
            ans.push_back(ind);
            bitmask |= (1<<ind);
            last = ind;
        }
        return ans;
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        int ans = INT_MAX;
        vector<int> ansStr;
        for(int i=n-1;i>=0;i--){
            memset(dp,-1,sizeof(dp));
            first = i;
            int recAns = recSolve(1<<i,nums,i);
            if(recAns < ans){
                ans = recAns;
                ansStr = genStr(i,nums);
            }
            else if(recAns == ans){
                ansStr = min(ansStr,genStr(i,nums));
            }
        }
        return ansStr;
    }

};