class Solution {
public:
    
    bool solve(vector<int>& nums, int diff){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]-nums[i]!=diff)
                return false;
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
       for(int i=0;i<l.size();i++){
            vector<int> check( (nums.begin()+l[i]) , (nums.begin()+r[i]+1) );
            sort(check.begin(), check.end());
            ans.push_back(solve(check, check[0]-check[1]));
        }
        return ans;
    }
};