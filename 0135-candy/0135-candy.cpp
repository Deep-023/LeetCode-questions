class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> left(n), right(n);
        left[0]=0;right[n-1]=n-1;
        
        for(int i=1;i<n;i++){
            if(r[i-1] >= r[i])
                left[i] =  i;
            else
                left[i] = left[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            if(r[i+1] < r[i])
                right[i] = right[i+1];
            else
                right[i] = i;
        }
        
        
        int sum=n;
        for(int i=0;i<n;i++){
            sum += max(right[i]-i, i-left[i]);
        }
        return sum;
    }
};