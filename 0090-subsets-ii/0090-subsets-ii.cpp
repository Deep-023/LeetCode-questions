class Solution {
public:
    set<vector<int>> ans;
    
    void solve(vector<int>& nums,int idx, int n, vector<int>& output){
        
        if(idx >= n){
            vector<int> a = output;
            sort(a.begin(),a.end());
            ans.insert(a);
            return;
        }
        
        solve(nums,idx+1,n,output);
        output.push_back(nums[idx]);
        solve(nums,idx+1,n,output);
        output.pop_back();
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        solve(nums,0,nums.size(),output);
        vector<vector<int>>anss;
        for(auto& str : ans ){
            anss.push_back(str);
        }
        return anss;
    }
};