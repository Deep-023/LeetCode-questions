class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(nums[0]);
        temp.push_back(nums[1]);
        
        int n = nums.size();
        
        if(n%3 != 0)
            return {};
        
        for(int i=2;i<n;i++){
            
            if(nums[i] > nums[i-1]+k || nums[i] > nums[i-2]+k){
                return {};
            }
            temp.push_back(nums[i]);
            if((i+1) % 3 == 0){
                ans.push_back(temp);
                temp = {};
                if(i+1<n)
                    temp.push_back(nums[++i]);
                if(i+2<n)
                    temp.push_back(nums[++i]);
            }
        }
        
        
        return ans;
        
    }
};