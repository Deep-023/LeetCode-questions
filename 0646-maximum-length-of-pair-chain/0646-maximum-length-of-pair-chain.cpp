class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans=1;
        for(int i=0;i<pairs.size()-1;i++){
            int count=1, k=i;
            for(int j=i+1;j<pairs.size();j++){
                if(pairs[k][1]<pairs[j][0]){
                    k=j;
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};