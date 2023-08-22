class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int tcount=0;
        int lcount = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<target)
                lcount++;
            else if(nums[i]==target)
                tcount++;
        }
        lcount--;
        int j=1;
        while(j<=tcount){
            ans.push_back(lcount+j++);
        }
        
        return ans;
    }
};