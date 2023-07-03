class Solution {
public:
    
    void solve(vector<int>nums, int index, vector<vector<int>>&ans,set<vector<int>>& sett){
        if(index >= nums.size()){
            if(!sett.count(nums)){
                sett.insert(nums);
                ans.push_back(nums);
            }
            return;
        }
        for(int i = index; i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans,sett);
            swap(nums[i],nums[index]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> sett;
        vector<vector<int>>ans;
        solve(nums,0,ans,sett);
        return ans;
    }
};