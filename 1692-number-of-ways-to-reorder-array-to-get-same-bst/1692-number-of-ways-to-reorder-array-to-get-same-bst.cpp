class Solution {
public:
const int MOD = 1e9+7;

    long long power(long long x, long long y, long long m) {
    if (y == 0)
        return 1;
    long long p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

    long long modInverse(long long a, long long m) {
        return power(a, m - 2, m);
    }

    // Function to calculate combinations (n choose k)
    long long int comb(long long int n, long long int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        k = min(k, n - k);  // Take advantage of symmetry
        long long int c = 1ll;
        for (long long int i = 0; i < k; ++i) {
            c = ((c % MOD) * ((n - i)% MOD)) % MOD;
            c = (c * modInverse(i + 1, MOD)) % MOD;
        }
        return c;
    }

    // Recursive DP function
    long long int dp(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 1;

        int root = nums[0];
        vector<int> left, right;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long int leftWays = dp(left);
        long long int rightWays = dp(right);
        long long int combination = comb(n - 1, left.size());

        return (((leftWays * rightWays)%MOD)* combination) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        return (dp(nums) - 1 + MOD) % MOD;
    }
};