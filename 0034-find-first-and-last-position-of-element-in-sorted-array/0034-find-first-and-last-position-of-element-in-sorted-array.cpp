class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(),left=-1,right=-1;
        int start = 0, end= n-1;
        int mid = start + (end-start)/2;
        
        while(start<end){
            if(nums[mid]>=target)
                end = mid;
            else
                start = mid+1;
            mid = start + (end-start)/2;
           // cout<<"hello"<<" "<<start<<" "<<end<<endl;
        }
        if(start>=0&& start<n && nums[start]==target )
        left = start;
        
        start = 0, end= n-1;
        mid = start + (end-start)/2;
        while(start<=end){
            //cout<<"bye";
            if(nums[mid]<=target)
                start = mid+1;
            else
                end = mid-1;
            mid = start + (end-start)/2;
        }
        if(end>=0 && end<n && nums[end]==target)
        right = end;
        
        return {left,right};
    }
};