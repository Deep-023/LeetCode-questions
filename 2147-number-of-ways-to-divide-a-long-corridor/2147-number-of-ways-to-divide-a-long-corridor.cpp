class Solution {
public:
    int numberOfWays(string corridor) {
        long ans = 0; 
        int count=0,left=0, mod=1e9+7;
        int n = corridor.size();
        for(int i=0;i<n;i++){
            
            if(count==2){
                if(corridor[i]=='S')
                    ans *= i-left;
                ans = ans%mod;
                
            }
            
            if(corridor[i]=='S'){
                count++;
                left = i;
                if(count==2 && ans==0)
                    ans = 1;
                if(count>2)
                    count=1;
            }
        }
        return count==1 ? 0 : ans;
        
    }
};