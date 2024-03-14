class Solution {
public:
    
    vector<int> zIndex(string& str){
        int n = str.size();
        vector<int>z(n);
        z[0]=n;
        for(int i=1,l=0,r=0;i<n;i++){
            if(i<=r)
                z[i] = min(z[i-l],r-i+1);
            for(int& j=z[i];i+j<n && str[j]==str[i+j];j++);
            if(z[i]>r-i+1){
                l=i;
                r = z[i]+i-1;
            }   
        }
        return z;
    }
    
    
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        unordered_map<int64_t,int> hash;
        long long mod = 1e17+3;
        long long ans = 0;
        
        for(int i=0;i<words.size();i++){
            vector<int> z = zIndex(words[i]);
            int64_t val = 0;
            int n = words[i].size();
            for(int j=0;j<n;j++){
                val = ((27LL*val)%mod + (1LL + words[i][j]-'a'))%mod;
                if(z[n-j-1]==j+1){
                    ans += hash[val];
                }
            }
            hash[val]++;
        }
        
        return ans;
    }
};
