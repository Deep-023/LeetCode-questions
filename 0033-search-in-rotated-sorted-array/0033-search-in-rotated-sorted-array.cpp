class Solution {
public:
    int findPivot(vector<int>& nums){
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<end){
            if(nums[mid]>=nums[end]){
                start = mid+1;
            }
            else
                end = mid;

            mid = start + (end-start)/2;
        }
        return start;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int start = 0, end = nums.size()-1;
        if(target >= nums[pivot] && target <= nums[end]){
            start = pivot;
        }
        else
            end = pivot-1;
        int mid = start + (end-start)/2;
        while(start<=end){
            if (nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                start = mid+1;
            }
            else
                end = mid-1;
            mid = start + (end-start)/2;
        }

        return -1;
    }
};