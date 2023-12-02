class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26,0);
        for(int i=0;i<chars.size();i++){
            count[chars[i]-'a']++;
        }
        
        vector<int> count2(26);
        int ans=0;
        for(int i=0;i<words.size();i++){
            fill(count2.begin(),count2.end(),0);
            int flag = 1;
            for(int j=0;j<words[i].size();j++){
                count2[words[i][j]-'a']++;
                
                if(count2[words[i][j]-'a'] > count[words[i][j]-'a']){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                cout<<words[i]<<endl;
                ans+= words[i].size();
            }
        }
        
        return ans;
    }
};