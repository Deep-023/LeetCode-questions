/*class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n= shifts.size();
        int n1= s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++)
                s[j] = (s[j]+shifts[i]%26-'a')%26 + 'a';  
        }
        return s;
    }
};*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n= shifts.size();
        for(int i=n-2;i>=0;i--){
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        }
        for(int i=0;i<n;i++)
            s[i] = (s[i]+shifts[i] -'a')%26 + 'a';

        return s;
    }
};