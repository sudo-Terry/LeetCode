class LRUCache {
private:
    int cap;
    list<int> lru_list;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // LRU 갱신
        if (cache.find(key) != cache.end()) {
            lru_list.erase(cache[key].second);
            lru_list.push_front(key);
            cache[key].second = lru_list.begin();
            
            return cache[key].first;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lru_list.erase(cache[key].second);
            lru_list.push_front(key);
            cache[key] = {value, lru_list.begin()};
        } else {
            // 새로운 키를 넣어야 함
            if (cache.size() >= cap) {
                int lru_key = lru_list.back();
                lru_list.pop_back();
                cache.erase(lru_key);
            }
            
            lru_list.push_front(key);
            cache[key] = {value, lru_list.begin()};
        }
    }
};
