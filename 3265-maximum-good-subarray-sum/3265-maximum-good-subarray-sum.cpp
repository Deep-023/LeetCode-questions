class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> cumulativeSums;
        long long currentSum = 0;
        long long maxSum = LLONG_MIN;

        for (int value : nums) {
            if (cumulativeSums.count(value - k)) {
                long long minValue = cumulativeSums[value - k];
                maxSum = max(maxSum, currentSum + value - minValue);
            }
            if (cumulativeSums.count(value + k)) {
                long long minValue = cumulativeSums[value + k];
                maxSum = max(maxSum, currentSum + value - minValue);
            }

            cumulativeSums[value] = min(cumulativeSums.count(value) ? cumulativeSums[value] : LONG_MAX, currentSum);
            currentSum += value;
        }

    return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};