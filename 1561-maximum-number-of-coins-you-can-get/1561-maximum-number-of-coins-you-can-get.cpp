class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), ans=0;
        /*priority_queue<int> pq(piles.begin(),piles.end());
        int ans = 0,i=1;
        while(i++<=n/3){
            pq.pop();
            ans += pq.top();
            pq.pop();
        }*/
        
        sort(piles.begin(),piles.end(), greater<int>());
        for(int i=1;i<(n-n/3);i+=2){
                ans+=piles[i];
        }
        return ans;
    }
};