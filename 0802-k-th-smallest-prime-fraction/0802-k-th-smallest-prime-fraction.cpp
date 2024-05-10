typedef pair<double,pair<int,int>> pp;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pp> pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double val = arr[i]*1.0/arr[j];
                if(pq.size()<k || pq.top().first>val){
                    pq.push({val,{arr[i],arr[j]}});
                    if(pq.size()>k){
                        pq.pop();
                    }
                }
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};