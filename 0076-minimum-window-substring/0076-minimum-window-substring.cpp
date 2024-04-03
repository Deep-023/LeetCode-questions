class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size() ;
        int start = 0 , end = 0 ;
        unordered_map<char,long int>map,map2 ;
        int minStart = -1 ;
        int temp = 0;
        int mini = INT_MAX ;
        for(auto i : t){
            map2[i]++ ;
        }
        bool  check = false ;
        while((end<n) && (start<n)){
            if(map2[s[end]]>0){
                   if(map[s[end]] < map2[s[end]]){
                       temp++;
                   }
                   map[s[end]]++;
               }
           while(temp==m){
                if(mini > min(mini,end-start+1)){
                        mini = min(mini,end-start+1) ;
                        minStart = start ;
                }
                if(map2[s[start]]>0){
                      map[s[start]]--;
                      if(map[s[start]] < map2[s[start]]){
                            temp--;
                      } 
                }
                start++;
           }
           end++;
           if(start>end) end++;
        }
        return  minStart == -1 ?   ""  : s.substr(minStart,mini);
    }
};