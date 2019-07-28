class LRUCache {
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); //Find the key. Move actual node to front.
        cacheMap[key] = cacheList.begin();   //update itera postion.
        return cacheMap[key] ->value;        //Actaul is map->list->value
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){
            if(cacheList.size()==capacity){
                cacheMap.erase(cacheList.back().key); //erase last in the node from both list and map.
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key,value));   //list and node make the new one.
            cacheMap.insert(make_pair(key,cacheList.begin()));
        }
        else{
            cacheMap[key]->value = value;  //just update value and iter.
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k,int v) : key(k), value(v){};
    };
    list<CacheNode> cacheList;    //This list is the actual storage.
    int capacity;
    unordered_map<int,list<CacheNode>::iterator> cacheMap;  //This map is for search. Contain iter is easy to search in list. And we don't need to maintain its position.
};