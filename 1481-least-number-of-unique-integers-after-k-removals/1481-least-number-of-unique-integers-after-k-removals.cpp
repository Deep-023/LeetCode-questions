class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto& i:mp){
            pq.push({i.second,i.first});
        }
        
        while(!pq.empty() && k>=pq.top().first){
                k -= pq.top().first;
                pq.pop();
        }
        
        return pq.size();
    }
};