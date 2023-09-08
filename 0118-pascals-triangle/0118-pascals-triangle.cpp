class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};
        if(numRows == 2)
            return {{1},{1,1}};
        vector<vector<int>> ans = {{1},{1,1}};
        for(int i=3;i<= numRows;i++){
            vector<int> num;
            num.push_back(1);
            int n = ans.size()-1;
            for(int j=0;j<ans[n].size()-1;j++)
                num.push_back(ans[n][j]+ans[n][j+1]);
            num.push_back(1);
            ans.push_back(num);
        }
        return ans;
    }
};