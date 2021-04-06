#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int count1 = 0, count2 = 0;
        if ((len1 + len2) & 1) { // odd
            int temp;
            while (count1 < len1 && count2 < len2) {
                if (nums1[count1] <= nums2[count2]) {
                    temp = nums1[count1];
                    count1++;
                } else {
                    temp = nums2[count2];
                    count2++;
                }
                if (count1 + count2 == (len1 + len2) / 2 + 1) return temp;
            }
            while (count1 < len1) {
                count1++;
                if (count1 + count2 == (len1 + len2) / 2 + 1) return nums1[count1 - 1];
            }
            while (count2 < len2) {
                count2++;
                if (count1 + count2 == (len1 + len2) / 2 + 1) return nums2[count2 - 1];
            }
        } else {
            double temp1, temp2 = 0;
            while (count1 < len1 && count2 < len2) {
                if (nums1[count1] <= nums2[count2]) {
                    temp1 = temp2;
                    temp2 = nums1[count1];
                    count1++;
                } else {
                    temp1 = temp2;
                    temp2 = nums2[count2];
                    count2++;
                }
                if (count1 + count2 == (len1 + len2) / 2 + 1) return (temp1 + temp2) / 2;
            }
            while (count1 < len1) {
                temp1 = temp2;
                temp2 = nums1[count1];
                count1++;
                if (count1 + count2 == (len1 + len2) / 2 + 1) return (temp1 + temp2) / 2;
            }
            while (count2 < len2) {
                temp1 = temp2;
                temp2 = nums2[count2];
                count2++;
                if (count1 + count2 == (len1 + len2) / 2 + 1) return (temp1 + temp2) / 2;
            }
        }
        return -1;
    }
};
