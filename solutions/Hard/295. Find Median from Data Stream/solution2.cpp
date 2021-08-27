#include <set>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> nums;
    multiset<int>::iterator left, right;
    MedianFinder() : left(nums.end()), right(nums.end()) {}
    
    void addNum(int num) {
        int n = nums.size();
        nums.insert(num);
        if (n == 0) { // empty
                left = right = nums.begin();
        } else if (n & 1) { // odd
            if (num < *left) left--;
            else right++;
        } else { // even
            if (num > *left && num < *right) {
                left++;
                right--;
            } else if (num <= *left) {
                right--;
                left = right;
            } else {
                left++;
                right = left;
            }
        }
    }
    
    double findMedian() {
        return (*left + *right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */