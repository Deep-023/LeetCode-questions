class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0, n= nums.size();
        vector<int>prefixSum(n,0);
        vector<int>postSum(n,0);
        
        for(int i=0;i<n;i++){
            prefixSum[i] = sum;
            sum += nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            postSum[i] = sum;
            sum += nums[i];
        }
        
        for(int i=0;i<n;i++){
            nums[i] = ((nums[i]*(i+1))-prefixSum[i]) - ((nums[i]*(n-i))-postSum[i]);
        }
        
        return nums;
    }
};