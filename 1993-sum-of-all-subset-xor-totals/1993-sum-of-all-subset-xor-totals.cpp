class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0,n=nums.size();
        queue<pair<int,int>> q;
        q.push({0,-1});
        while(!q.empty()){
            auto [x,node] = q.front();
            q.pop();
            ans += x;
            for(int i = node+1;i<n;i++){
                q.push({x^nums[i],i}); 
            }
        }

        return ans;
    }
};