class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        priority_queue<int> pq(piles.begin(),piles.end());
        int ans = 0,i=1;
        while(i++<=n/3){
            pq.pop();
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};