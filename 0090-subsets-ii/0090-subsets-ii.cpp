class Solution {
public:
    /*set<vector<int>> ans;
    
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
    }*/
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        int start;
        for(int i=0; i<nums.size(); i++) {
            if(i==0 || nums[i] != nums[i-1]) start = 0;
            for(int end=result.size(); start<end; start++){
                vector<int> clone = result[start];
                clone.push_back(nums[i]);
                result.push_back(clone);
            }
        }
        return result;
    }
};