class Solution {
    long mod = 1000000007;
    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        long[] dp = new long[n+1];
        long[] preSum = new long[n+1];

        dp[0]=1;preSum[0]=1;
        Deque<Integer> minq = new ArrayDeque<>();
        Deque<Integer> maxq = new ArrayDeque<>();
        int left = 0;
        for(int i=0;i<n;i++){
            while((!minq.isEmpty()) && (nums[minq.getLast()]>nums[i])){
                minq.pollLast();
            }
            minq.addLast(i);
            while((!maxq.isEmpty()) && (nums[maxq.getLast()]<nums[i])){
                maxq.pollLast();
            }
            maxq.addLast(i);

            while(left<i && (nums[maxq.peekFirst()]-nums[minq.peekFirst()])>k){
                if(left == maxq.peekFirst()){ maxq.pollFirst(); }
                if(left == minq.peekFirst()){ minq.pollFirst(); }
                left++;
            }

            long ways = preSum[i] - (left>0 ? preSum[left-1] : 0) ;
            dp[i+1] = (ways%mod + mod)%mod;
            preSum[i+1] = preSum[i]+dp[i+1];
        }

        return (int)dp[n];

    }
}