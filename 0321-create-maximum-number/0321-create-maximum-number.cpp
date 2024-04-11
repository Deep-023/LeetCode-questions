class Solution {
public:
    vector<int> mxArr(vector<int>& arr, int k){
        vector<int> ans(k);
        int j=0,n=arr.size();
        for(int i=0;i<n;i++){
            while( n-i>k-j  && j>0 && ans[j-1]<arr[i]) j--;
            if(j<k)
                ans[j++]=arr[i];
            
        }
        return ans;
    }
    
    vector<int> merge(vector<int> arr, vector<int> arr2){
        int i=0,j=0,n=arr.size(),m=arr2.size();
        vector<int> ans(n+m);
        for(int k=0;k<n+m;k++){
            ans[k] = (greater(arr,i,arr2,j) ? arr[i++] : arr2[j++]);
        }
        return ans;
    }
    
    bool greater(vector<int>& ans, int i, vector<int>& res, int j){
        int n=ans.size(),m=res.size();
        while(i<n && j<m && ans[i]==res[j])
            i++,j++;
        
        return j==m || (i<n && ans[i]>res[j]);  
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m=nums2.size();
        vector<int> res;
        for(int i=max(0,k-m);i<=k && i<=n; i++){
            vector<int>ans = merge(mxArr(nums1,i),mxArr(nums2,k-i));
            if(greater(ans,0,res,0)){
                res = ans;
            }
        }
        return res;
    }  
};
