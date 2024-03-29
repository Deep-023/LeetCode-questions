class Solution {
public:
    
    int solve(string& s, int k, int l, int r){
        
        if(l>=r)
            return 0;
        
        int count[26];
        memset(count,0,sizeof(count));
        for(int i=l;i<r;i++)
            count[s[i]-'a']++;
        
        int flag = 1;
        for(int i=0;i<26;i++)
            if(count[i]<k && count[i]>0) flag=0;
        
        if(flag)
            return r-l;
        
        int ans = 0,start=l;
        for(int i=l;i<r;i++){
            if(count[s[i]-'a']<k){
                ans = max(ans,solve(s,k,start,i));
                start = i+1;
            }
        }
        ans = max(ans,solve(s,k,start,r));
        return ans;
        
    }
    
    int longestSubstring(string s, int k) {
         if(s.size()==0 || s.size()<k)
             return 0;
         if(k<2) return s.size();
         return solve(s,k,0,s.size());
    }
};
