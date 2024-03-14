class Solution {
public:
    
    vector<int> zIndex(string& s){
        int n = s.size();
        vector<int> z(n,0);
        z[0] = 0;
        for(int i=1,l=0,r=0;i<n;i++){
            if(i<=r){
                z[i] = min(z[i-l],r-i+1);
            }
            for(int &j = z[i]; i+j<n && s[j]==s[i+j];j++)
            if (z[i]>r-i+1){
                l=i;
                r=i+z[i]-1;
            }
        }
        return z;
    }
    
    int minimumTimeToInitialState(string word, int k) {
        vector<int> z = zIndex(word);
        for (int i = k, n = word.size(); i < n; i += k)
            if (z[i] == n - i)
                return i / k;
        return (word.size() + k - 1) / k;
    }
};