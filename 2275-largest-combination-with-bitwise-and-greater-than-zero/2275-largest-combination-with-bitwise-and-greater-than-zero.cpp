class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxLength=0;
        for(int i=0; i<=24; i++){  //coz constraint is 10^7 which is 2^24
             int length =0;
            for(int cand : candidates){
                if( cand & (1<<i))
                    length++;
            }
            maxLength = max(length,maxLength);
        }
        return maxLength;
    }
};