class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(word == targetWord)
                return level;
                
            for(int i=0;i<word.size();i++){
                char og = word[i];
                for(int j=0;j<26;j++){
                    word[i] = j+'a';
                    if(st.count(word)){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i] = og;
            }
            
        }
        
        return 0;
    }
};