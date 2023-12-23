class Solution {
    
    struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        // Implement a hash function for pair<int, int>
        return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
    }
};
  
public:
    bool isPathCrossing(string path) {
        pair<int,int> origin;
        unordered_set<pair<int,int>, PairHash> set;
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