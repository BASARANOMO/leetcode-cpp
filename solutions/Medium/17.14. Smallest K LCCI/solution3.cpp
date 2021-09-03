#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) swap(arr[++i], arr[j]);
        }
        swap(arr[right], arr[++i]);
        return i;
    }
    int randomized_pivot_partition(vector<int>& arr, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(arr[i], arr[right]);
        return partition(arr, left, right);
    }
    void randomized_selected(vector<int>& arr, int left, int right, int k) {
        if (left >= right) return;
        int pos = randomized_pivot_partition(arr, left, right);
        int num = pos - left + 1; // number of elements less than the chosen pivot
        if (k == num) return;
        else if (k < num) randomized_selected(arr, left, pos - 1, k);
        else randomized_selected(arr, pos + 1, right, k - num);
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        srand(time(NULL));
        randomized_selected(arr, 0, arr.size() - 1, k);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) ans[i] = arr[i];
        return ans;
    }
};