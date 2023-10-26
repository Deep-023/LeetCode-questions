class Solution {
public:
       
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        sort(arr.begin(),arr.end());
        unordered_map<int,long long> m;
        int n = arr.size();
        long long ans = 1;
        m[arr[0]] = ans;
        for(int i=1;i<n;i++){
            long long sum = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && m.find(arr[i]/arr[j]) != m.end()){
                    sum = sum + m[arr[i]/arr[j]]* m[arr[j]];
                }
            }
            m[arr[i]] = sum;
            ans+=sum;
        }
        return ans%mod;
    }
}; 