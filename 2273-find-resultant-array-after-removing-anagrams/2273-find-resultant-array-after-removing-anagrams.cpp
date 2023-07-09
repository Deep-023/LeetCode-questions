class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string sett = "";
        vector<string> test = words;
        vector<string> ans;
        for(int i=0 ; i<words.size(); i++){
            sort(test[i].begin(), test[i].end());
            if(sett != test[i]){
                sett = test[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};