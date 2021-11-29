class Solution {
private:
    int m;
    int n;
    int total;
    unordered_map<int, int> map;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
        srand(time(nullptr));
    }
    
    vector<int> flip() {
        int x = rand() % total;
        vector<int> ans;
        total--;
        if (map.count(x)) ans = {map[x] / n, map[x] % n};
        else ans = {x / n, x % n};
        if (map.count(total)) map[x] = map[total];
        else map[x] = total;
        return ans;
    }
    
    void reset() {
        total = m * n;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */