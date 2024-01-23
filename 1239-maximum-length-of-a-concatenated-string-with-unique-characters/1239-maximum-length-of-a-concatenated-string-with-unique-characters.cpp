class Solution {
public:
    
    void solve(vector<string>& arr, vector<int>& count, int n , int idx, int total, int& ans){
        
        if(idx>=n){
            ans = max(ans,total);
            return;
        }
        
        int n1 = arr[idx].size();
        solve(arr,count,n,idx+1,total,ans);
        
        for(int i=0;i<n1;i++){
            count[arr[idx][i] - 'a']++;
            if(count[arr[idx][i] - 'a'] > 1)
            {
                for(int j=i;j>=0;j--){
                    count[arr[idx][j] - 'a']--;
                }
                return;
            }
        }
        
        solve(arr,count,n,idx+1,n1+total,ans);
        
        for(int i=0;i<n1;i++){
            count[arr[idx][i] - 'a']--;
        }
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> count(26,0);
        int ans = 0;
        solve(arr,count,n,0,0,ans);
        return ans;
    }
};