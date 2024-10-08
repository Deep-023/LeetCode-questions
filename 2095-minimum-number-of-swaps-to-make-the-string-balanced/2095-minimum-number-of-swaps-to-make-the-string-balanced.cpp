class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int net = 0;
        for(auto& c:s){
            if(c=='['){
                net++;
            }else{
                net--;
            }
            count = min(count,net);
        }
        count = count*-1;
        return (count+1)/2;
    }
};