class MyHashMap {
public:
    vector<vector<int>> m;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto it = m.begin(); it != m.end(); ++it){
            if(key==(*it)[0]){
                (*it)[1]=value;
                return;
            }
        }
        m.push_back({key,value});
    }
    
    int get(int key) {
        for(auto it = m.begin(); it != m.end(); ++it)
            if(key==(*it)[0])
                return (*it)[1];
        return -1;
    }
    
    void remove(int key) {
         for (auto it = m.begin(); it != m.end(); ++it){
             if((*it)[0]==key){
                 m.erase(it);
                 return;
             }
         }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */