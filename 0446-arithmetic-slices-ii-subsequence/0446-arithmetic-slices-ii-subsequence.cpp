class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long,long>> m(n);
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long diff = (long long)nums[i]- (long long)nums[j];
                m[i][diff]++;
                if(m[j].count(diff)){
                    m[i][diff] += m[j][diff];
                    ans += m[j][diff];
                }
            }
        }
        return (int)ans;
    }
};
/*
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& a) {
		long long ans = 0, n = a.size();
		vector<unordered_map<long, long>> dp(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				long long diff = (long long)a[i] - (long long)a[j];

				dp[i][diff]++;
				if (dp[j].count(diff)) {
					dp[i][diff] += dp[j][diff];
					ans += dp[j][diff];
				}
			}
		}
		return ans;
	}
};
*/