class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            if(i==0 || i==1)
                ans.push_back(i);
            else{
                if(i&1)
                    ans.push_back(ans[i/2]+1);
                else
                    ans.push_back(ans[i/2]);
            }
        }
        return ans;
    }
};