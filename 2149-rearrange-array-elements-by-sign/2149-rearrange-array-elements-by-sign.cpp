class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(i&1)
                nums[i]=neg[j++];
            else
                nums[i]=pos[k++];
        }
        return nums;
    }
};