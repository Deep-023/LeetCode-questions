typedef pair<int,int> pp;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<pp> check(1001,{0,0});
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[i]<0) check[num].first = 1;
            else check[num].second = 1;
        }
        
        for(int i=1000;i>=1;i--)
            if(check[i].first==1 && check[i].second==1) return i;

        return -1;
    }
};