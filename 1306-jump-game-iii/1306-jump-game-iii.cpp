class Solution {
public:
    bool solve(vector<int>& arr, int idx, int n, vector<int>& visited){
        if(idx>=n || idx<0 || visited[idx])
            return false;
        if(arr[idx]==0)
            return true;
        
        visited[idx]=1;
        return solve(arr,idx+arr[idx],n,visited) || solve(arr,idx-arr[idx],n,visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n,0);
        return solve(arr,start,n,visited);
    }
};