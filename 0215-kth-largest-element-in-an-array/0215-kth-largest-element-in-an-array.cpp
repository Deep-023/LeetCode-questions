class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> s(nums.begin(),nums.end());
        int count = 1;
        for(auto i:s){
            if(count==k)
                return i;
            count++;
        }
        return -1;
    }
};