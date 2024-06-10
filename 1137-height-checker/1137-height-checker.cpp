class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dummy = heights;
        sort(dummy.begin(),dummy.end());
        int ans = 0;
        for(int i=0;i<dummy.size();i++)
            if(dummy[i] != heights[i]) ans++;

        return ans;
    }
};