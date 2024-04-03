class LRUCache {
public:
    
    queue<int> q;
    unordered_map<int,pair<int,int>> mp;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end())
            return -1;
        
        mp[key].second++;
        q.push(key);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            mp[key].first = value;
        }else{
            if(mp.size()<size){
                mp[key] = {value,0};
            }else{
                while(mp[q.front()].second > 1){
                    mp[q.front()].second--;
                    q.pop();
                }
                
                mp.erase(q.front());
                q.pop();
                mp[key] = {value,0};
            }
        }
        mp[key].second++;
        q.push(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */