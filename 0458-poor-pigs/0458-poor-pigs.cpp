class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie; // this gives number of itrs
        int x = 0;
        
        while(pow(T+1,x) < buckets) //T+1 states will be there. if T is 2 states can be 0,1,2
            x++;
        
        return x;
    }
};