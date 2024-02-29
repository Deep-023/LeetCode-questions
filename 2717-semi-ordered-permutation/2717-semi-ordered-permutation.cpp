class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int a = min_element(nums.begin(),nums.end())-nums.begin();
        int b = max_element(nums.begin(),nums.end())-nums.begin();
        
        int n = nums.size()-1;
        
        if(a>b)
            return a+(n-b)-1;
        return a+(n-b);
    }
};