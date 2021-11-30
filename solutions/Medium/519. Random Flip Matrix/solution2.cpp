class Solution {
private:
    int m;  
    int n;
    int total;
    vector<unordered_set<int>> buckets;
    int bucketSize;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        total = m * n;
        bucketSize = sqrt(m * n); // best time complexity for flip()
        for (int i = 0; i < total; i += bucketSize) buckets.push_back({});
        srand(time(nullptr));
    }
    
    vector<int> flip() {
        int x = rand() % total;
        int sumZero = 0;
        int curr = 0;
        total--;
        for (auto& bucket : buckets) {
            if (sumZero + bucketSize - bucket.size() > x) {
                for (int i = 0; i < bucketSize; i++) {
                    if (!bucket.count(curr + i)) {
                        if (sumZero == x) {
                            bucket.emplace(curr + i);
                            return {(curr + i) / n, (curr + i) % n};
                        }
                        sumZero++;
                    }
                }
            }
            curr += bucketSize;
            sumZero += bucketSize - bucket.size();
        }
        return {};
    }
    
    void reset() {
        for (auto& bucket : buckets) bucket.clear();
        total = m * n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */