class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
    
        int n = mat.size(),m=mat[0].size();
        vector<vector<int>> preSum(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                preSum[i][j] = mat[i][j] == '0' ? 0 : ( j>0 ? preSum[i][j-1]+1 : 1 );
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(preSum[i][j] != 0){
                    int mn = INT_MAX;
                    for(int k=i;k<n;k++){
                        if(preSum[k][j] == 0)
                            break;
                        else{
                            mn = min(mn,preSum[k][j]);
                            ans = max(ans,(k-i+1)*mn);
                        }
                    }   
                }
            }
        }
        
        
        return ans==INT_MIN ? 0 : ans;
        
    }
};