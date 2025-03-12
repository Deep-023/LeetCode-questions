class Solution {
public:
    long long getLessAll(string& s){
        long long freq[3];
        long long unq = 0, ans = 0, left=0;

        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a'] == 0) unq++;
            freq[s[i]-'a']++;
            while(unq==3){
                freq[s[left]-'a']--;
                if(freq[s[left]-'a']==0) unq--;
                left++;
            }

            ans += i-left+1;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        return n*1l*(n+1)/2 - getLessAll(s);
    }
};