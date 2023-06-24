class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto itr=nums.begin();
        for(;itr != nums.end();itr++){
            if(*itr == val){
                nums.erase(itr);
                itr--;
            }
        }
        return nums.size();
    }
};