class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX, ans1=INT_MAX, ans2=INT_MAX;
        unordered_map<int,int> m;
        for(auto i:nums1){
            m[i]++;
            ans1 = min(ans1,i);
        }
        for(auto i:nums2){
            m[i]++;
            ans2 = min(ans2,i);
            if(m[i]==2)
                ans = min(i,ans);    
        }
        
        if(ans != INT_MAX)
            return ans;
        
        if(ans1<ans2)
            return ans1*10+ans2;
        else
            return ans2*10+ans1;
        
            
    }
};