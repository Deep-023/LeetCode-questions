class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0,a=-1,b=-1,c=-1,n=garbage.size();
        for(int i=0;i<garbage.size();i++){
            int count =0;
            if(garbage[i].find('G') != -1 ){
                a =i;
                count += std::count(garbage[i].begin(), garbage[i].end(), 'G');
            }
            if(garbage[i].find('P') != -1 ){
                b=i;
                count += std::count(garbage[i].begin(), garbage[i].end(), 'P');
            }
            if(garbage[i].find('M') != -1 ){
                c=i;
                count += std::count(garbage[i].begin(), garbage[i].end(), 'M');
            }
            
            ans += count;
            if(i>0){
                ans += 3*travel[i-1];
            }
        }
        
        a++;b++;c++;
        while(a<n){
            if(a>0)
                ans-= travel[a-1];
            a++;
        }
        while(b<n){
            if(b>0)
                ans-= travel[b-1];
            b++;
        }
        while(c<n){
            if(c>0)
                ans-= travel[c-1];
            c++;
        }
        
        return ans;
    }
};