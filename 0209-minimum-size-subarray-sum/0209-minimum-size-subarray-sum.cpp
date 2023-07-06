class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count =0, ans=INT_MAX, sum=0, left=0, right=0;
        for(right=0;right<nums.size();right++){
            target -= nums[right];
            while(target<=0 && left<=right){
                    ans = min(ans, right-left+1);
                    target += nums[left];
                    left++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
/*class Solution {
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
};*/