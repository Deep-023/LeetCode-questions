class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> sets;
        unordered_map<int,int> map;
        for(int i =0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(auto it:map){
            sets.insert(it.second);
        }
        if(sets.size()==map.size())
        return true;
        return false;
    }
};