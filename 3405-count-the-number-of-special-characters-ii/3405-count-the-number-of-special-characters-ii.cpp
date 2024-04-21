class Solution {
public:
    int numberOfSpecialChars(string word) {
        int arr1[26], arr2[26];
        memset(arr1,-1,sizeof(arr1));
        memset(arr2,-1,sizeof(arr2));
        int n = word.size();
        
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z')
                arr1[word[i]-'a'] = i;
            else if(arr2[word[i]-'A']==-1)
                arr2[word[i]-'A'] = i;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(arr1[i]>-1 && arr2[i]>-1 && arr1[i]<arr2[i])
                ans++;
        }
        
        return ans;
    }
};