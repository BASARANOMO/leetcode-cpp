#include <vector>
using namespace std;

class Solution {
public:
    int findKthElem(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int idx1 = 0, idx2 = 0;
        int new_idx1, new_idx2;
        while (true) {
            if (idx1 == m) return nums2[idx2 + k - 1];
            if (idx2 == n) return nums1[idx1 + k - 1];
            if (k == 1) return min(nums1[idx1], nums2[idx2]);
            new_idx1 = min(m - 1, idx1 + k / 2 - 1);
            new_idx2 = min(n - 1, idx2 + k / 2 - 1);
            if (nums1[new_idx1] <= nums2[new_idx2]) {
                k -= new_idx1 - idx1 + 1;
                idx1 = new_idx1 + 1;
            } else {
                k -= new_idx2 - idx2 + 1;
                idx2 = new_idx2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) & 1) return findKthElem(nums1, nums2, (m + n) / 2 + 1);
        else return (findKthElem(nums1, nums2, (m + n) / 2) + findKthElem(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
    }
};
