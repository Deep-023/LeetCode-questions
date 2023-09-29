class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end(),greater<char>());
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i] != s[i+1]){
                swap(s[i],s[n-1]);
                break;
            }
        }
        return s;
        
    }
};