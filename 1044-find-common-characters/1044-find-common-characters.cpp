class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int m = words[0].size();
        unordered_map<char,int> mp;
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(i==0){
                for(int j=0;j<words[i].size();j++){
                    mp[words[i][j]]++;
                }
            }else{
                unordered_map<char,int> mp2;
                for(int j=0;j<words[i].size();j++){
                    mp2[words[i][j]]++;
                }
                for(char j='a';j<='z';j++){
                    mp[j] = min(mp[j],mp2[j]);
                }
            }
        }

        for(char i='a';i<='z';i++){
            if(mp[i]>0){
                while(mp[i]-- > 0)
                    ans.push_back(string(1,i));
            }
        }
        return ans;
    }
};