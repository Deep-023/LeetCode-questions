class Solution {
public:
    static bool compare(int a,int b){
        int x = 0;
        int y = 0;
        int c = a,d=b;
        while(a>0){
            if(a&1)x++;  //alt __builtin_popcount(x) can be used for counting no. of ones
            a = a>>1;
        }
        while(b>0){
            if(b&1)y++;
            b = b>>1;
        }
        if(x==y)
            return c<d;
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};