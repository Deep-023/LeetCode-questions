class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> DisMax(n,INT_MAX);
        int count=INT_MAX;
        for(int i=0;i<n;i++){
            if(seats[i]==1)
                count = 0;
            else if(count!=INT_MAX)
                DisMax[i] = ++count;
        }
        count=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1)
                count=0;
            else if(count!=INT_MAX)
                DisMax[i] = min(DisMax[i],++count);
        }
        int maxDistance=0;
        for(int i=0;i<n;i++){
            if(seats[i] == 0 && maxDistance < DisMax[i]){
                maxDistance = DisMax[i];
            }
        }
        return maxDistance;
    }
};