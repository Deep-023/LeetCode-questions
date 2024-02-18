class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> count(n,0);
        vector<long long> top(n,0);
        int mxCount = 0;
        
        for(int i=0;i<meetings.size();i++){
            pair<long long,int> mn = {1e18,-1};
            bool flag = false;
            for(int j=0;j<n;j++){
                if(top[j]<mn.first){
                    mn.second = j;
                    mn.first = top[j];
                }
                if(top[j]<=meetings[i][0]){
                    flag=true;
                    count[j]++;
                    mxCount = max(mxCount,count[j]);
                    top[j]=meetings[i][1];
                    break;
                }
            }
            
            if(flag==false){
                count[mn.second]++;
                mxCount = max(mxCount,count[mn.second]);
                top[mn.second]+=(1ll*(meetings[i][1]-meetings[i][0]));
            }
        }
        
        for(int i=0;i<n;i++){
            if(count[i]==mxCount)
                return i;
        }
        
        return -1;
            
    }
};
