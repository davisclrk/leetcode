#include <iostream>
#include <map>
#include <queue>

using namespace std;

class LRUCache {
public:
    map<int, int> cache;
    queue<int> lru;
    map<int, int> freq;
    int cap;
    int cur;
    LRUCache(int capacity) {
        cap = capacity;
        cur = 0;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            lru.push(key);
            freq[key]++;
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)){
            cache[key] = value;
            lru.push(key);
            freq[key]++;
            return;
        }

        if (cur == cap) {
            while (true){
                int k = lru.front();
                lru.pop();
                if (freq[k] == 1){
                    cache.erase(k);
                    freq[k]--;
                    break;
                } else {
                    freq[k]--;
                }
            }
            cur--;
        }
        lru.push(key);
        freq[key]++;
        cache[key] = value;
        cur++;
    }
};

// my solution. uses queue to track least recently used as it will sort times linearly
// frequency map tracks if a key in the queue is used later, i.e. has been referenced later and thus is not the lru

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */