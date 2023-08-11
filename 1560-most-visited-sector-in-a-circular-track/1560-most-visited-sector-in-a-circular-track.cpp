class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        unordered_map<int,int> m;
        int n1=rounds.size();
        for(int i=1;i<n1;i++){
            for(int j = rounds[i-1];j!=rounds[i];){
                m[j]++;
                if(j>=n)
                    j = 1;
                else
                    j++;
            }
        }
        m[rounds[n1-1]]++;
        int mx=0;
        
        vector<int>ans;
        for(auto i:m)
            mx = max(mx,i.second);
        
        for(auto i:m){
            if(mx==i.second)
                ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};