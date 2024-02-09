class Solution {
public:
    vector<int> temp;
    void solve(int i, vector<int> &nums, vector<int> &ans, vector<int> &dp){
        if(i >= nums.size()){
            if(ans.size() > temp.size()){
                temp = ans;
                
            }
            return;
            
        }

        //if at present index it satisfies modullus condition and also has greater length before then 
        //its better we consider
        //example
        //{3, 4, 15, 28, 32}-array after sorting

        //{3, }              {}
        //a.{3, 15} b.{3, }      c.{15, }
        //here its just time and space waste to consider 'c' when there is a bigger length array 'a' with 15 included
        //everything will be exactly same from 15 for both 'a' , 'c' so better to consider only 'a' to move forward
        if((ans.size() == 0 || nums[i] % ans.back()  == 0) && dp[i] < (int)ans.size()+1){
            dp[i] = ans.size()+1;
            ans.push_back(nums[i]);
            solve(i+1, nums, ans, dp);
            ans.pop_back();
        }

        solve(i+1, nums, ans, dp);


    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(),-1);
        solve(0, nums, ans, dp);
        
        return temp;
    }
};