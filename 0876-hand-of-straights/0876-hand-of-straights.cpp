class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize > 0)
            return false;
        map<int,int> mp;
        int n = hand.size();
        for(int i=0;i<n;i++)
            mp[hand[i]]++;
        
        int k = n/groupSize;
        while(k--){
            int i=0,last = -1;
            for(auto& j:mp){
                if(i==groupSize) break;
                if(last != -1 && ((last+1) != j.first))
                    return false;
                last = j.first;
                j.second--;
                if(j.second==0)
                    mp.erase(j.first);
                i++;
            }
            if(i<groupSize) return false;
        }
        return true;
    }
};