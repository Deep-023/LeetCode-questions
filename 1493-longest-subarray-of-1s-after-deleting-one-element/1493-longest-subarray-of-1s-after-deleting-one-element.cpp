class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int first = 0, second = -1, flag = false;
        int count1 =0 ,count2=0,i =0, ans=0;
        while(nums[i]!=1 && i<nums.size()){
            i++;
            flag = true;
        }
        while(i<nums.size()){
            
            if(nums[i] != 1){
                first++;
                second++;
                flag = true;
            
                if(first==2){
                    count1=0;
                    first=0;
                }
                else if(second==2){
                    count2=0;
                    second=0;
                }
            }
            
            if(first<2 && nums[i]==1 ){
                count1++;
            }
            if(second<2 && second >=0 && nums[i]==1 ){
                count2++;
            }
            
            int res = max(count1, count2);
            ans = max(ans,res);
            i++;
        }
        if(first==0 && second==-1 && flag==false)
            return nums.size()-1;
        return ans;
    }
};