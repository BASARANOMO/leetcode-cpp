#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m, ptr2 = n;
        while (ptr1 > 0 && ptr2 > 0) {
            if (nums1[ptr1 - 1] >= nums2[ptr2 - 1]) {
                nums1[ptr1 + ptr2 - 1] = nums1[ptr1 - 1];
                ptr1--;
            } else {
                nums1[ptr1 + ptr2 - 1] = nums2[ptr2 - 1];
                ptr2--;
            }
        }
        while (ptr2 > 0) {
            nums1[ptr1 + ptr2 - 1] = nums2[ptr2 - 1];
            ptr2--;
        }
    }
};