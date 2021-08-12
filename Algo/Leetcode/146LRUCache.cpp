class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;

        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); // move to head. Dict no need to touch since it will change
        return cacheMap[key]->value;
    }

    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){ // not in the list
            if(cacheList.size()==capacity){       // remove least recently access one
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value)); // add new one to the front
            cacheMap[key] = cacheList.begin();           // update the pos in dict
        } else {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); // if exist, update to front and update value
            cacheList.front().value = value;
        }
    }
    int capacity;
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v): key(k), value(v) {};
    };
    list<CacheNode> cacheList;
    map<int, list<CacheNode>::iterator> cacheMap;
};
