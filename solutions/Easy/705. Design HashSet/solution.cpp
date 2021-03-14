class MyHashSet {
private:
    int exists[1000001] = {0};
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }

    void add(int key) {
        exists[key] = true;
    }

    void remove(int key) {
        exists[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return exists[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
