class Solution {
public:
    bool check(int mid , vector<int>&q , int n){
        int count=0;
        for(int i=0;i<q.size();i++){
            int a=q[i];
            int b=a/mid;
            int c=a%mid;
            count+=b+(c!=0);

        }
        if(count<=n) return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int maxi=*max_element(q.begin(),q.end());
        int left=1;
        int right=maxi;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(mid,q,n)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
        
    }
};