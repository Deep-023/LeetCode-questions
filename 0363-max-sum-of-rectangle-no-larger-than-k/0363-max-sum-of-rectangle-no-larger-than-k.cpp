class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& M, int lim) {
        int R = M.size(), C = M[0].size();
        vector<vector<int>> rowSum(R, vector<int>(C, 0));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                rowSum[i][j] = M[i][j] + (j > 0 ? rowSum[i][j - 1] : 0);
            }
        }

        int mx = INT_MIN;
        for (int i = 0; i < C; i++) {
            for (int j = i; j < C; j++) {
                set<int> sums;
                sums.insert(0); // To handle the case when a single value is within limit
                int sum = 0;
                for (int k = 0; k < R; k++) {
                    int val = rowSum[k][j] - (i > 0 ? rowSum[k][i - 1] : 0);
                    sum += val;
                    // Find the smallest prefix sum larger than sum - lim
                    auto it = sums.lower_bound(sum - lim);
                    if (it != sums.end()) {
                        mx = max(mx, sum - *it);
                    }
                    sums.insert(sum);
                }
            }
        }

        return mx;
    }
};