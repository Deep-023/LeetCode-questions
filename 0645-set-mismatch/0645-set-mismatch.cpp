class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> count(n+1,0);
        int sum = n*(n+1)/2;
        int sumarr = 0;
        int num=0;
        for(int i=0;i<n;i++){
            sumarr += nums[i];
            count[nums[i]]++;
            if(num==0 &&  count[nums[i]] == 2)
                num = nums[i];
        }
        
        int diff = sum - sumarr;
        return {num,num+diff};
    }
};