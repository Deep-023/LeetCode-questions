class Solution {
public:
    using pp = pair<int,int>;
    int findMaximizedCapital(int k, int w, vector<int>& prof, vector<int>& cap) {
        priority_queue<pp, vector<pp>, greater<pp>> minPq;
        priority_queue<int> maxPq;

        for(int i=0;i<prof.size();i++){
            minPq.push({cap[i],prof[i]});
        }

        while(k--){
            while(!minPq.empty() && minPq.top().first <= w){
                maxPq.push(minPq.top().second);
                minPq.pop();
            }
            if(maxPq.empty())
                break;
            w += maxPq.top();
            maxPq.pop();
        }

        return w;
    }
};