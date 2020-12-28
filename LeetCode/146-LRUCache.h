class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            keys.erase(it->second.second);
            keys.push_front(key);
            it->second.second = keys.begin();
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {      // find
            int key = it->first;
            keys.erase(it->second.second);
            keys.push_front(key);
            it->second.second = keys.begin();
        }
        else {                       // not found
            if (keys.size() == cap) {
                cache.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
        }
        cache[key] = make_pair(value, keys.begin());
    }
private:
    int cap;
    typedef list<int>::iterator li;
    unordered_map<int, pair<int, li>> cache;
    list<int> keys;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */