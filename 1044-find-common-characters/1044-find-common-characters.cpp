class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int m = words[0].size();
        int mp[26]={0};
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(i==0){
                for(int j=0;j<words[i].size();j++){
                    mp[words[i][j]-'a']++;
                }
            }else{
                int mp2[26]={0};
                for(int j=0;j<words[i].size();j++){
                    mp2[words[i][j]-'a']++;
                }
                for(int j=0;j<26;j++){
                    mp[j] = min(mp[j],mp2[j]);
                }
            }
        }

        for(int i=0;i<26;i++){
            if(mp[i]>0){
                while(mp[i]-- > 0)
                    ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};