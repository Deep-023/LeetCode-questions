class Solution {
public:
    static bool compare(int a,int b){
        int x = 0;
        int y = 0;
        int c = a,d=b;
        while(a>0){
            a = a&(a-1);
            x++;  //alt __builtin_popcount(x) can be used for counting no. of ones
            
        }
        while(b>0){
            b = b&(b-1);
            y++;
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