class LRUCache {
public:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key){
        if(mp.count(key)){
            int val = mp[key]->second;
            l.erase(mp[key]);
            l.push_front({key, val});
            mp[key] = l.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value){
        if(!mp.count(key)){
            l.push_front({key, value});
            mp[key] = l.begin();

            if(mp.size() > cap){
                auto last = mp[l.back().first];
                mp.erase(l.back().first);
                l.pop_back();
            }

            return;
        }

        get(key);
        mp[key]->second = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */