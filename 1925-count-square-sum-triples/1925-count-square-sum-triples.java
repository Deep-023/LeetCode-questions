class Solution {

    int gcd(int a , int b){
        return a%b == 0 ? b : gcd(b,a%b);
    }

    public int countTriples(int n) {
        int count = 0; 
        for(int i=1;i*i<n;i++){
            for(int j=i+1; (j*j + i*i) <= n ;j++){
                int c = i*i + j*j;
                
                if(gcd(j,i) != 1 || ( ((j^i)&1)!=1) ) continue;
                if(c>n) break;
                
                count += ((n/c)*2);
            }
        }

        return count;
    }
}