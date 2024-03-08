class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count[101];
        memset(count,0,sizeof(count));
        int n = nums.size(),mx = INT_MIN;
        
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            mx =  max(mx,count[nums[i]]);
        }
        
        int sum = 0;
        for(int i=0;i<101;i++){
            if(count[i]==mx)
                sum += count[i];
        }
        
        return sum;
        
        
    }
};