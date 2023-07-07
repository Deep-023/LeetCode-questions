class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int tcount =0 , fcount =0, left=0, ans=0;
        for(int right=0;right<a.size();right++){
            if(a[right]=='F')
                fcount++;
            else
                tcount++;
            
                while(fcount>k && tcount>k){
                     if(a[left]=='F')
                        fcount--;
                    else
                        tcount--;
                    left++;
                }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};