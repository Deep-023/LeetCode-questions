class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int least=0, max=0,ans=0;
        unordered_map<int,int> count;
        for(int right = 0;right<n ;right++){
            if(++count[nums[right]]==1){
                if(--k < 0){
                    count[nums[max++]]--;
                    least = max;
                }
            }
            
            if(k<=0){
                while(count[nums[max]] > 1)
                    --count[nums[max++]];
                ans += max-least+1;
            }
        }
        return ans;
    }
};