class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int> a;
        int n = s.size();
        for(int i=0;i<n;i++)
            a[s[i]]++;
        
        int count=0;
        for(auto& i:a){
            i.second = max(0,(i.second-n/4));
            if(i.second>0) count++;
        }

        if(count==0) return 0;

        int left = 0,ans=INT_MAX;
        unordered_map<char,int> b = a;

        for(int i=0;i<n;i++){
            if(a[s[i]] != 0){
                b[s[i]]--;
                if(b[s[i]]==0)
                    count--;
            }

            if(count==0) ans = min(ans,i-left+1);

            while(count==0 && left<i){
                if(a[s[left]]>0){
                    b[s[left]]++;
                    b[s[left]] = min(b[s[left]],a[s[left]]);
                    if(b[s[left]]>0)
                        count++;
                }
                ans = min(ans,i-left+1);
                left++;
            }
        }
        return ans;
    }
};