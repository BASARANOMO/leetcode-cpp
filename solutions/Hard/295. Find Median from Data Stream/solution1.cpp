#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> bufferGreater;
    priority_queue<int, vector<int>, less<int>> bufferLess;
    MedianFinder() {}
    
    void addNum(int num) {
        if (bufferLess.empty() || num <= bufferLess.top()) {
            bufferLess.push(num);
            if (bufferGreater.size() + 1 < bufferLess.size()) {
                bufferGreater.push(bufferLess.top());
                bufferLess.pop();
            }
        } else {
            bufferGreater.push(num);
            if (bufferGreater.size() > bufferLess.size()) {
                bufferLess.push(bufferGreater.top());
                bufferGreater.pop();
            }
        }
    }
    
    double findMedian() {
        if (bufferLess.size() == bufferGreater.size()) return (bufferLess.top() + bufferGreater.top()) / 2.0;
        else return bufferLess.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */