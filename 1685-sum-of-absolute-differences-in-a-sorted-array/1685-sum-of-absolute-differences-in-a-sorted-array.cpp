class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0, n= nums.size();
        vector<int>prefixSum(n,0);
        //vector<int>postSum(n,0);
        
        for(int i=0;i<n;i++){
            prefixSum[i] = sum;
            sum += nums[i];
        }
        sum=0;
        /*for(int i=n-1;i>=0;i--){
            postSum[i] = sum;
            sum += nums[i];
        }
        sum=0;*/
        int temp;
        for(int i=n-1;i>=0;i--){
            temp = nums[i];
            nums[i] = ((nums[i]*(i))-prefixSum[i]) - ((nums[i]*(n-i-1))-sum);
            sum += temp;
        }
        
        return nums;
    }
};