class Solution {
public:
    int rev(int n){
        int num = 0;
        while(n){
            int rem = n%10;
            n /= 10;
            num = num*10 + rem;
        }
        return num;
    }
    
    int countNicePairs(vector<int>& nums) {
        int mod =1e9+7;
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]- rev(nums[i])]++;
        }
        
        long long ans = 0;
        for(auto& i:m){
            long long num = i.second;
            ans += (num%mod)*(num-1)/2;
            ans = ans%mod;
        }
        
        return ans;
        
    }
};