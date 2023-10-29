class Solution {
public:
    int countTexts(string p) {
        int mod = 1e9+7;
        long long ans = 1;
        for(int i=1;i<p.size();i++){
            int count = 1;
            long long a=8,b=1,c=2,d=4;
            long long num=1;
            while(p[i]==p[i-1]){
                count++;
                if(p[i] != '9' && p[i] != '7'){
                   if(count > 3){
                        num = ((b+c)%mod+d)%mod;
                        b=c;
                        c=d;
                        d=num;
                    }else{
                        num = pow(2,count-1);
                   }
                }else{
                   if(count > 4){
                        num = (((a+b)%mod+c)%mod+d)%mod;
                        b=c;
                        c=d;
                        d=a;
                        a=num;
                    }else{
                        num = pow(2,count-1);
                   }
            }
                i++;
        }
            cout<<num<<"  ";
            ans = (ans*num)%mod;
    }
        return ans%mod;
    }
};