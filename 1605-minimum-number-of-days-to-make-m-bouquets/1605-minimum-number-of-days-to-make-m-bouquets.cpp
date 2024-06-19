class Solution {
public:

    bool valid(vector<int>& bl,int m, int k, int days){
        int count = 0, adj=0;
        for(int i=0;i<bl.size();i++){
            if(bl[i]<=days){
                adj++;
            }else adj=0;
            if(adj>=k){
                count++;
                adj = 0;
            }    
            if(count>=m) return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*1ll*k>n) return -1;

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low<high){
            int mid = low + (high-low)/2;
            if(valid(bloomDay,m,k,mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};