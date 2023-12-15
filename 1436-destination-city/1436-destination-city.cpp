class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>m;
        for(auto i:paths){
            m[i[0]]++;
            m[i[1]];
        }
        
        for(auto i:m){
            if(i.second==0)
                return i.first;
        }
        return "";
        
    }
};