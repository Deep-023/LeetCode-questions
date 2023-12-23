class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int,int> origin;
        set<pair<int,int>> set;
        origin = {0,0};
        set.insert({0,0});
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                origin.second++;
            }else if(path[i]=='E'){
                origin.first++;
                
            }else if(path[i]=='S'){
                origin.second--;
            }
            else if(path[i]=='W'){
                origin.first--;
            }
            
            if(set.count(origin))
                    return true;
            else
                set.insert(origin);
        }
        return false;
    }
};