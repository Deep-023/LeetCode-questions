class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> dq;
        int n = deck.size();
        for(int i=0;i<n;i++){
            dq.push(i);
        }
        
        vector<int> res(n);
        
        for(auto &i : deck){
            int idx = dq.front();
            dq.pop();
            res[idx] = i;
            if(!dq.empty()){
                dq.push(dq.front());
                dq.pop();
            }
        }
        return res;
    }
};
