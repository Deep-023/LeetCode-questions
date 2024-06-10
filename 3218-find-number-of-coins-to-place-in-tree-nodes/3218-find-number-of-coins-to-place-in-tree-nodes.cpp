#define ll long long
class Solution {
public:
    vector<ll> arr[20001];
    vector<ll> ans;

     vector<ll> dfs(vector<int>& cost, ll node, ll par) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        priority_queue<ll> pq2;
        if(cost[node]>=0) pq.push(cost[node]);
        else pq2.push(cost[node]);

        for (auto& neighbor : arr[node]) {
            if (neighbor != par) {
                vector<ll> childs = dfs(cost, neighbor, node);
                for (auto& childCost : childs) {
                    if(childCost>=0){
                        if (pq.size()<3) pq.push(childCost);
                        else if(pq.top()<childCost){
                            pq.pop();
                            pq.push(childCost);
                        }
                    }else{
                        if (pq2.size()<3){
                            pq2.push(childCost);
                        }
                        else if(pq2.top()>childCost){
                            pq2.push(childCost);
                            pq2.pop();
                        }
                    }
                }
            }
        }
    
        vector<ll> top;
        ll mul = 1;
        while (!pq.empty()) {
            top.push_back(pq.top());
            pq.pop();
        }
        reverse(top.begin(),top.end());
        
        ll mul2 = 1,len=top.size();
        while(!pq2.empty()){
            top.push_back(pq2.top());
            pq2.pop();
        }

        if (top.size() < 3) {
            ans[node] = 1;
        } else {
            mul = top[0]*top[1]*top[2];
            int n1 = top.size();
            mul2 = top[0]*top[n1-2]*top[n1-1];
            ans[node] = max({0ll, mul, mul2});
        }

        return top;
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        ll n = edges.size()+1;
        for(ll i=0;i<n-1;i++){
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        ans = vector<ll>(n,0);
        dfs(cost,0,-1);
        return ans;
    }
};