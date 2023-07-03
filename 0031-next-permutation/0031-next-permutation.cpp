class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i = nums.size()-2;i>=0;i--){ //find first peak;
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i = nums.size()-1;i>=index && index != -1; i--){
            if(nums[index]<nums[i]){ // swap with closest larger number
                swap(nums[index],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end()); //can use sort but hame pta ha ki iske age dec order me he hai array so agar reverse kiya toh it also works. logically sort krna ha swapped element ke age se.
    }
};


