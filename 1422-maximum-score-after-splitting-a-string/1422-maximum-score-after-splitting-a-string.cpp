class Solution {
public:
    int maxScore(string s) {
      int zeroes = 0;
      int mx = INT_MIN;
      for(int i=0;i<s.size();i++){
          if(s[i]=='0')
              zeroes++;
      }
      int ones=0;
      for(int i=s.size()-1;i>0;i--){
          if(s[i]=='1')
              ones++;
          if(s[i]=='0')
              zeroes--;
          mx = max(mx,ones+zeroes);
      }
        
        return mx;
    }
};