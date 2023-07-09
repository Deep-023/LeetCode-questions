class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mapp;
        int sum=0, maxSum = 0;
        for(int i=0;i<chars.size();i++){
            if(vals[i] != 0)
            mapp[chars[i]] = vals[i];
            else
            mapp[chars[i]] = INT_MIN;
        }
        
        for(int i=0;i<s.size();i++){
            if(mapp[s[i]] == INT_MIN)
                sum += 0;
            else if(mapp[s[i]]){
                sum += mapp[s[i]];
            }
            else
                sum += s[i]-'a'+1;
            if(sum<0)
                sum=0;
            maxSum = max(maxSum, sum);
        }
          
        return maxSum;
    }
};