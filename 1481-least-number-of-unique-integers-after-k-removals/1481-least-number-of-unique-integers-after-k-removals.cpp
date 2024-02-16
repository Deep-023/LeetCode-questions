class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& i:mp){
            pq.push(i.second);
        }
        
        while(!pq.empty() && k>=pq.top()){
                k -= pq.top();
                pq.pop();
        }
        
        return pq.size();
    }
};