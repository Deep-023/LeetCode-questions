class Solution {
public:
    bool solve(vector<int>& arr, int idx, int n, vector<int>& visited){
        if(idx>=n || idx<0)
            return false;
        if(arr[idx]==0)
            return true;
        if(visited[idx])
            return false;
        visited[idx]=1;
        bool ans1 = solve(arr,idx+arr[idx],n,visited);
        bool ans2 = solve(arr,idx-arr[idx],n,visited);
        visited[idx]=0;
        return ans1 || ans2;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n,0);
        return solve(arr,start,n,visited);
    }
};