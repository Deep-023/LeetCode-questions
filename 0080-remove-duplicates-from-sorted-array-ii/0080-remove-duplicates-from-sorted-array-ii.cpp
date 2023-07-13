class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;  // Pointer to track the position to place the next unique element
        for (int n : nums) {
            if (i < 2 || n > nums[i-2]) {
                // The current element is either the first or second occurrence of a number
                // or it is greater than the number before the last unique element
                // So, it can be included in the updated array
                nums[i++] = n;  // Place the current element at the correct position
            }
        }
        return i;  // Return the new length of the array with duplicates removed
    }
};