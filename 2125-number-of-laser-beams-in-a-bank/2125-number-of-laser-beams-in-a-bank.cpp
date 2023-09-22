class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> c(n,0);
        for(int i=0;i<n;i++){
            c[i] = count(bank[i].begin(), bank[i].end(), '1');
        }
        
        int ans=0;
        int i=0;
        for(int j=0;j<n;j++){
            if(c[j] && i<j){
                ans += c[i]*c[j];
                i=j;
            }   
        }
        return ans;
    }
};