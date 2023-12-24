class Solution {
public:
    int minOperations(string s) {
        int ans=0,ans2=0;
            for(int i=0;i<s.size();i++){
                if(i&1){
                    if(s[i]!='0')
                        ans++;
                }
                else{
                    if(s[i]!='1')
                        ans++;
                }
            }
            for(int i=0;i<s.size();i++){
                if(i&1){
                    if(s[i]!='1')
                        ans2++;
                }
                else{
                    if(s[i]!='0')
                        ans2++;
                }
            }
            
        
        return min(ans,ans2);
    }
};