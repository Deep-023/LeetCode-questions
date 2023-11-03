class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        vector<string> ans;
        for(int i=1;i<=n && j<target.size();i++){
            if(target[j]==i){
                j++;
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
                
        }
        return ans;
    }
};