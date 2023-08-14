/* 
Solution {
class public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> m;
        int count=0, n=word.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(word[j] != 'a' && word[j] != 'e' && word[j] != 'i' && word[j] != 'o' && word[j] != 'u')
                    break;
                m[word[j]]++;
                if(m['a']>=1 && m['e']>=1 && m['i']>=1 && m['o']>=1 && m['u']>=1)
                    count++;
            }
            m.clear();
        }
        return count;
    }
};
*/

class Solution {
public:
    int countVowelSubstrings(string word) {
        string v = "aeiou"; 
        unordered_map<char,int> m;
        int i,j=0,k=0,count=0,vow=0;
        for(i=0;i<word.size();i++){
            if(v.find(word[i]) != string::npos){ //string::npos == -1;
                m[word[i]]++;
                if(m[word[i]]==1)
                    vow++;
                
                while(vow==5){
                    m[word[k]]--;
                    if(m[word[k]] == 0)
                        vow--;
                    k++;
                }
                count += k-j;
            }
        
        else{
            m.clear();
            j=k= i+1;
            vow=0;
        }      
    }
        return count;
    }
};