class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> nums = {a,b,c};
        sort(nums.begin(),nums.end());
        
        if(nums[0]==nums[1]-1 && nums[1]==nums[2]-1)
            return {0,0};
        
        int min = 0;
        int diff1 = nums[1]-nums[0]-1, diff2= nums[2]-nums[1]-1;
        
        if(diff1 == 1 || diff2 ==1 )
            min = 1;
        else if(diff1>1 && diff2>1)
            min = 2;
        else if(diff1==0 || diff2==0)
            min = 1;
        
        int max = nums[1]-nums[0]-1 + (nums[2]-nums[1]-1);
        
        return {min,max}; 
        
    }
};