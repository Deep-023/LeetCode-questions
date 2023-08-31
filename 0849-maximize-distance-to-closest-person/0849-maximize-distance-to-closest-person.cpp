class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> leftMax(n,INT_MAX);
        vector<int> rightMax(n,INT_MAX);
        int count=INT_MAX;
        for(int i=0;i<n;i++){
            if(seats[i]==1)
                count = 0;
            else if(count!=INT_MAX)
                leftMax[i] = ++count;
        }
        count=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1)
                count=0;
            else if(count!=INT_MAX)
                rightMax[i] = ++count;
        }
        int maxDistance=0;
        for(int i=0;i<n;i++){
            if(seats[i] ==0 && maxDistance < min(leftMax[i],rightMax[i])){
                maxDistance = min(leftMax[i],rightMax[i]);
            }
        }
        return maxDistance;
    }
};