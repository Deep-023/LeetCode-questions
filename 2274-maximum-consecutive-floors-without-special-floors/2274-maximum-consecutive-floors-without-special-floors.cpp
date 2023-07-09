class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int maxFloor = 0, n = special.size();
        for(int i = 0; i<n ;i++){
            if(bottom != special[i]){
                maxFloor = max(maxFloor, special[i]-bottom);
            }
            bottom = special[i]+1;
        }
        maxFloor = max(maxFloor, top-special[n-1]);
        return maxFloor;
    }
};