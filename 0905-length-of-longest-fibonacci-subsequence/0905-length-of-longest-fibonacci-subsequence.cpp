class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,vector<pair<int,int>>> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[arr[i]+arr[j]].emplace_back(arr[j],2);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if (mp.count(arr[i])) {
                auto& pairs = mp[arr[i]];
                for (auto& j : pairs) {
                    int newNum = arr[i] + j.first;
                    mp[newNum].emplace_back(arr[i], j.second + 1);
                    ans = max(ans, j.second + 1);
                }
            }
        }

        return ans;
    }
};