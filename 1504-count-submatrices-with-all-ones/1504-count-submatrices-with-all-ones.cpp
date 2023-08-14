class Solution{
public:  
int helper(vector<vector<int>>& mat, int a, int b, int m, int n) {
        
        int count = 0;
        int bound = n;
        
        for (int i=a; i<m; i++) {
            for (int j=b; j<bound; j++) {
                if (mat[i][j]) count += 1;
                else bound = j;
            }
            if(bound==b)
                return count;
        }
        
        return count;

    }

    int numSubmat(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                count += helper(mat, i, j, m, n);
            }
        }
        
        return count;

    }
};