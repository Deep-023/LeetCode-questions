class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int left = 0, vow = 0, con = 0, temp=0;
        string vowels = "aeiou";
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            if( vowels.contains(word[i]) ){
                if(mp[word[i]] == 0) vow++;
                mp[word[i]]++;
            }
            else con++;

            while(con>k){
                if(vowels.contains(word[left])){
                    mp[word[left]]--;
                    if(mp[word[left]]==0)vow--;
                }else{
                    con--;
                }
                left++;
                temp = 0;
            }

            if(vow==5 && con==k){
                if(temp>0) temp--;
                while(left<i){
                    temp++;
                    if( vowels.contains(word[left]) ){
                        if(mp[word[left]] == 1)break;
                        mp[word[left]]--;
                    }else{
                        break;
                    }
                    left++;
                }
            }
            ans += temp;    
        }
        return ans;
    }
};