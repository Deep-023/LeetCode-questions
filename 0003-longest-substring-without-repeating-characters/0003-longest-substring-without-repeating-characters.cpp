class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount=0;
        unordered_set<char> inp;
        int left=0;
        for(int i=0;i<s.size();i++){
            if(inp.count(s[i])==0){
                inp.insert(s[i]);
                maxCount = max(maxCount, i-left+1);
            }
            else{
                while(inp.count(s[i])){
                    inp.erase(s[left]);
                    left++;
                }
                inp.insert(s[i]);
            }
        }

        return maxCount;
    }
};