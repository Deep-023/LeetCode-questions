class Solution {
public:
    int bitwiseComplement(int n) {
        int bitmask=0;
        int num = n;

        if(n==0)
        return 1;
        
        while(num!=0){
            bitmask = ( bitmask << 1 ) | 1;
            num =  num >> 1;
        }

        int answer = (~n) & bitmask;
        return answer;
    }
};