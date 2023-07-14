class RandomizedSet {
private:
    unordered_map<int,int> m;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
       if(m[val]){
           return false;
       }
        else{
            m[val]=1;
        }
        return true;
    }
    
    bool remove(int val) {
        if(m[val]){
            m.erase(val);
            return true;
        }
        m.erase(val);
        return false;
    }
    
    int getRandom() {
        int j = (rand()%m.size());
        auto k = m.begin();
        while(j--){
            k++;
        }
        return k->first;
            
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */