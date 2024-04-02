class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr1[256]={0};
        int arr2[256]={0};
        int n = s.size(),m=t.size();
        
        if(n != m) return false;
        
        for(int i=0;i<n;i++){
            if(arr1[s[i]] == 0 && arr2[t[i]]==0)
            {
                arr1[s[i]]=t[i];
                arr2[t[i]]=s[i];
            }else{
                if(arr1[s[i]] != t[i])
                    return false;                   
            }
        }
        
        return true;
    }
};