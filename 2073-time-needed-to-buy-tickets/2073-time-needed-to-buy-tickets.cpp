class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = (tickets[k]-1)*n + (k+1);
        
        for(int i=0;i<n;i++)
            ans += min(0,i<=k ? tickets[i]-tickets[k] : tickets[i]-tickets[k]+1);
        return ans;
    }
};

