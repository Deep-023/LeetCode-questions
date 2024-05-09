#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happi, int k) {
        priority_queue<int> pq(happi.begin(),happi.end());
        int a = 0; 
        ll ans = 0;
        while(k-- && !pq.empty()){
            int add = max(pq.top()-a,0);
            pq.pop();
            a++;
            ans += add;
        }
        return ans;
    }
};