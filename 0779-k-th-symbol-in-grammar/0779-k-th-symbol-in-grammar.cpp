class Solution {
public:
    
    int solve(long long n, int k){
        
        if(n==1){
            return 0;
        }
        
        if(k<=n/2){
            return solve(n/2,k);
        }else{
            return !solve(n/2,k-n/2);
        }
        
        return 0;
    }
    
    int kthGrammar(int n, int k) {
        return solve(pow(2,n-1),k);
    }
};