class MyHashMap {
private:
    static const int SIZE = 1009; // Prime number for better distribution
    vector<list<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }

    void put(int key, int value) {
        int index = hash(key);
        for (auto& p : buckets[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[index].emplace_back(key, value);
    }

    int get(int key) {
        int index = hash(key);
        for (const auto& p : buckets[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
