class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        deque<int> dq;
        int n = deck.size();
        for(int i=0;i<n;i++){
            dq.push_back(i);
        }
        
        vector<int> res(n);
        
        for(auto &i : deck){
            int idx = dq.front();
            dq.pop_front();
            res[idx] = i;
            if(!dq.empty()){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return res;
    }
};

// 17 13 11 7 5 3 2

//17
//13 17 
//11 17 13
//7 13 11 17
//5 17 7 13 11
//3 11 5 17 7 13
//2 13 3 11 5 17 7