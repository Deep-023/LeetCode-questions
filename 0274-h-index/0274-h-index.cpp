class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        unordered_map<int,int> m;
        int ans = INT_MIN;
        int n = c.size();
        for(int i=0;i<n;i++){
            if(!m.count(c[i]))
                m[c[i]] = n-i;
        }
        for(auto i:m){
            if(i.first <= i.second){
                ans = max(ans,i.first);
            }
            else
                ans= max(ans,i.second);
        }
        return ans;
    }
};