class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s; // Special case where numRows is 1, return the input as-is
        }
        int n = s.size();
        vector<vector<char>> table(numRows, vector<char>(1000,' '));
        string ans;
        int i=0,j=0;
        for(auto k:s){
            table[i][j] = k;
            if(i<numRows-1 && j%(numRows-1)==0)
                i++;
            else{
                j++;
                i--;
            }
        }
        
        for(i=0;i<numRows;i++){
            for(j=0;j<1000;j++){
               if(table[i][j] != ' ')
                   ans.push_back(table[i][j]);
            }
        }
        return ans;
    }
};