class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        
        int oddMax = 0,ans=0;
        for(auto i:mp){
            if((i.second%2) == 0){
                ans += i.second;
            }else{
                ans += i.second-1;
                oddMax = 1;
            }
        }
        if(oddMax) return ans+1;
        return ans;
    }
};