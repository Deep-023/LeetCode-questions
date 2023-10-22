class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int ans=0, i=1 , j=piles.size()-1;
        while(i<j){
            ans += piles[i];
            i+=2;
            j--;
        }
        return ans;
    }
};