#define ll long long

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll> preSum(n);
        vector<int> right(n);
        ll ans = 0;
        int mod = 1e9+7, left=0;
        
        stack<int> stk;
        stk.push(-1);
        
        for(int i=0;i<n;i++){
            preSum[i] = nums[i] + (i>0 ? preSum[i-1] : 0);
            preSum[i] = preSum[i];   
        }
        
        for(int i=n-1;i>=0;i--){
            while(stk.top() != -1 && nums[stk.top()]>=nums[i])
                    stk.pop();
            right[i] = stk.top();
            stk.push(i);
        }
    
        while(stk.top() != -1)
            stk.pop();
        
        for(int i=0;i<n;i++){
            
            while(stk.top() != -1 && nums[stk.top()]>=nums[i])
                    stk.pop();
            left = stk.top();
            stk.push(i);
            
            ll sum = (right[i]!=-1 ? preSum[right[i]-1] : preSum[n-1])-(left!=-1 ? preSum[left] : 0);
            ans = max(ans,nums[i]*1ll*sum);
        }
        
        
        return ans%mod;
    }
};