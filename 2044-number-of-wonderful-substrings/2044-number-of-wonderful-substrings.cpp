class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int count[1024];
        count[0]=1;
        int mask = 0;
        long long res=0;
        for(int i=0;i<word.size();i++){
            mask ^= (1<<(word[i]-'a'));
            res += count[mask];
            for(int j=0;j<10;j++){
                res += count[mask^(1<<j)];    
            }
            count[mask]++;
        }
        return res;
    }
};