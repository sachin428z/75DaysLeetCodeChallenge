class MyHashMap {
private: 
    static const int SIZE=1009;
    vector<list<pair<int,int>>> table;

    int hash(int key) {
        return key%SIZE;
    }
public:
    MyHashMap(): table(SIZE){ 
    }
    
    void put(int key, int value) {
       int idx=hash(key);
       for(auto& kv: table[idx]) {
        if(kv.first==key) {
            kv.second=value;
            return;
        }
       } 
       table[idx].emplace_back(key,value);
    }
    
    int get(int key) {
        int idx=hash(key);
        for(const auto& kv: table[idx]) {
            if(kv.first==key) return kv.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=hash(key);
        for(auto it=table[idx].begin();it!=table[idx].end();it++) {
            if(it->first==key) {
                table[idx].erase(it);
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