/*class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count =0, ans=INT_MAX, sum=0, left=0, right=0;
        for(right=0;right<nums.size();right++){
            if(target - nums[right] > 0){
                target -= nums[right];
            }
            else{
                ans = min(ans, right-left+1);
                while(target<=nums[right] && left<nums.size()){
                    target += nums[left];
                    left++;
                }
                right--;
            }
        }
        if(target<=0)
            ans = min(ans, right-left+1);
        return ans==INT_MAX?0:ans;
    }
};*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size();
		
        int i,j,sum, minlen=n+1;
        i=j=sum=0;
		
        while(j<n){
            sum+=a[j]; // acquiring rear element
			
            while(i<=j && sum>=target){
                minlen = min(minlen,j-i+1);
                sum-=a[i]; // releasing front element
                i++;
            }
			
            j++;
        }
        
        return (minlen==n+1 ? 0:minlen);
    }
};