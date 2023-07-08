class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1)
            return 0;
        
        vector<long long int>ans;
        for(int i=1;i<weights.size();i++)
            ans.push_back(weights[i] + weights[i-1]);
        
        sort(ans.begin(),ans.end());
        
        long long int maxSum=0;
        long long int minSum=0;
        for(int i=0;i<k-1;i++){
            minSum+=ans[i];
            maxSum+=ans[weights.size() - 2 - i];
        }
        
        return maxSum - minSum;
    }
};