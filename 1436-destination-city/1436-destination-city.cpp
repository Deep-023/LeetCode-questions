class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>>m;
        for(auto i:paths){
            m[i[0]].push_back(i[1]);
            m[i[1]];
        }
        
        for(auto i:m){
            if(i.second.empty())
                return i.first;
        }
        return "";
        
    }
};