class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int number = 15,ans=0; 
        if(left==0 || right==0)
            return 0;
        
        int n = (int)(log2(left)); 
        string a = bitset<64>(left).to_string().substr(64 - n - 1);
        n = (int)(log2(right)); 
        string b = bitset<64>(right).to_string().substr(64 - n - 1);
        
        if(a.size()!=b.size()){
            return 0;
        }
        
        int i=0;
        n=a.size();
        while(i<n && a[i] == b[i]){
            if(a[i]&1)
                ans += pow(2,n-1-i);
            i++;
        }
        
        return ans;
        
    }
};