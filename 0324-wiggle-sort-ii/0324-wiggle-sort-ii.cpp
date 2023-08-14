class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> addOn(nums);
        sort(addOn.begin(),addOn.end());
        int n = nums.size();
        int k=n-1;
        for(int i=1;i<n;i=i+2){
            nums[i] = addOn[k--];
        }
        for(int i=0;i<n;i=i+2){
            nums[i] = addOn[k--];
        }
    }
};