class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans = INT_MAX;
        unordered_map<int,int> m;
        for(auto i:nums1)
            m[i]++;
        for(auto i:nums2){
            m[i]++;
            if(m[i]==2)
                ans = min(i,ans);
        }
        
        if(ans != INT_MAX)
            return ans;
        
        if(nums1[0]<nums2[0])
            return nums1[0]*10+nums2[0];
        else
            return nums2[0]*10+nums1[0];
        
            
    }
};