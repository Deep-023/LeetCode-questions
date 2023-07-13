class Solution {
public:
    int res(unordered_map<char,int>&mp){
    int mf=-1;
    int lf=INT_MAX;
    for(auto &it:mp){
        mf=max(mf,it.second);
        lf=min(lf,it.second);
       
    }
     return mf-lf;
}
    
    int beautySum(string s) {
        int sum=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> m;
            for(int j=i; j< n;j++){
                m[s[j]]++;
                sum += res(m);
            }
        }
        return sum;
    }
};