class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> count(n,0);
        vector<long long> top(n,-1);
        int mxCount = 0;
        
        for(int i=0;i<meetings.size();i++){
            pair<long long,int> mn = {1e18,-1};
            for(int j=0;j<n;j++){
                if(top[j]==-1){
                    mn.second = j;
                    break;
                }
                long long diff = top[j]-meetings[i][0];
                if(diff <= 0){
                    mn = {diff,j};
                    break;
                }
                if(diff < mn.first){
                    mn = {diff,j};
                }
            }
            
            if(top[mn.second] == -1){
                count[mn.second]++;
                mxCount = max(mxCount,count[mn.second]);
                top[mn.second] = meetings[i][1];
            }else{
            count[mn.second]++;
            mxCount = max(mxCount,count[mn.second]);
            top[mn.second] = top[mn.second]-meetings[i][0] < 0 ? meetings[i][1] : meetings[i][1]+mn.first; 
            
            }
        }
        
        for(int i=0;i<n;i++){
            if(count[i]==mxCount)
                return i;
        }
        
        return -1;
            
    }
};