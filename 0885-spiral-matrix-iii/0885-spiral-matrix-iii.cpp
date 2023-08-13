class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        vector<vector<int>>ans;
        int count = rows*cols;
        int i=1;
        int dir = 1;
        while(count){
            for(int k=0;k<i;k++){
                if(rs<rows && cs<cols && rs>=0 && cs>=0){
                    ans.push_back({rs,cs});
                    count--;
                }
                cs += dir;
            }
            for(int k=0;k<i;k++){
                if(rs<rows && cs<cols && rs>=0 && cs>=0){
                    ans.push_back({rs,cs});
                    count--;
                }
                rs += dir;
            }
            i++;
            dir = dir*(-1);
        }
            
        return ans;
    }
};