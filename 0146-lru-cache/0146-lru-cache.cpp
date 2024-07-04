class LRUCache {
public:
    int capacity;
    std::list<int> keys; // List of keys in order of usage
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
         if (cache.find(key) == cache.end()) {
            return -1;
        }
        // Move the accessed key to the front of the list (most recently used)
        keys.splice(keys.begin(), keys, cache[key].second);
        return cache[key].first;
    }
    
    void put(int key, int value) {
         if (cache.find(key) != cache.end()) {
            // Update the value and move the key to the front
            cache[key].first = value;
            keys.splice(keys.begin(), keys, cache[key].second);
        } else {
            if (cache.size() >= capacity) {
                // Remove the least recently used key-value pair
                int lruKey = keys.back();
                keys.pop_back();
                cache.erase(lruKey);
            }
            // Add the new key-value pair
            keys.push_front(key);
            cache[key] = {value, keys.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */