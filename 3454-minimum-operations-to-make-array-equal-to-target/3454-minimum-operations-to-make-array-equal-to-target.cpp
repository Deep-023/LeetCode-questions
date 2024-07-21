class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0,n=nums.size();
        vector<int> diff;
        for(int i=0;i<n;i++){
            diff.push_back(nums[i]-target[i]);
        }
        
        int mx = 0, mn=0;
        for(int i=0;i<n;i++){
            if(diff[i]==0){
                mx = 0;
                mn = 0;
                continue;
            }
            if(diff[i]<0){
                ans += abs(min(0,diff[i]-mn));
                mn = diff[i];
                mx = 0;
            }else{
                ans += max(0,diff[i]-mx);
                mx = diff[i];
                mn = 0;
            }
        }

        return ans;
    }
};