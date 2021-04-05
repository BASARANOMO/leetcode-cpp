#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n);
        int count1 = 0, count2 = 0;
        while (count1 < m && count2 < n) {
            if (nums1[count1] <= nums2[count2]) {
                temp[count1 + count2] = nums1[count1];
                count1++;
            } else {
                temp[count1 + count2] = nums2[count2];
                count2++;
            }
        }
        while (count1 < m) {
            temp[count1 + count2] = nums1[count1];
            count1++;
        }
        while (count2 < n) {
            temp[count1 + count2] = nums2[count2];
            count2++;
        }
        nums1 = temp;
    }
};