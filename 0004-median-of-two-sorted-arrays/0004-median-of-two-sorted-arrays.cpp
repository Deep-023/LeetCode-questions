class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size(), n2 = nums2.size(), i=0,j=0;
        int t = n1+n2;
        int med = t/2 + 1;
        while(i+j<=med && n1 && n2){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                n1--;
            }
            else if(nums2[j] < nums1[i]){
                ans.push_back(nums2[j]);
                 j++;
                n2--;
            }
            else{
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                j++;
                i++;
                n1--;n2--;
            }
        }
        while(i+j<=t && n1-- > 0){
            ans.push_back(nums1[i]);
            i++;
        }
        while(i+j<=t && n2-- > 0){
            ans.push_back(nums2[j]);
            j++;
        }
        
        if(t&1)
            return ans[t/2]*1.0;
        else{
            return (ans[t/2 - 1] + ans[t/2])*1.0/2;
        } 
        return 0.0;
    }
};