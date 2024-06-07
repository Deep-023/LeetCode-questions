class Solution {
public:
    class Trie{
        public:
        Trie* arr[26];
        bool isTerminal;

        Trie(){
            for(int i=0;i<26;i++) arr[i] = NULL;
            isTerminal = false;
        }
    };

    Trie* insert(vector<string>& dict){
        Trie* trie = new Trie();
        for(int i=0;i<dict.size();i++){
            Trie* temp = trie;
            for(int j=0;j<dict[i].size();j++){
                int ch = dict[i][j]-'a';
                if(temp->arr[ch] == NULL)
                    temp->arr[ch] = new Trie();
                temp = temp->arr[ch];
                if(j==dict[i].size()-1)
                    temp->isTerminal = true;
            }
        }
        return trie;
    }

    string check(string word, Trie* root){
        int count = 0,flag=1;
        Trie* temp = root;
        for(int i=0;i<word.size();i++){
            int ch = word[i]-'a';
            if(temp->arr[ch]==NULL) break;
            temp = temp->arr[ch];
            count++;
            if(temp->isTerminal) {flag = 0 ; break;}
        }

        return flag ? word : word.substr(0,count);
    }
    

    string replaceWords(vector<string>& dict, string sen) {
        Trie* root = insert(dict);
        string ans;

        stringstream s(sen);
        string word;

        while(s>>word){
            if(ans.size()>0) ans+=" ";
            ans += check(word,root);
        }
        return ans;
    }
};