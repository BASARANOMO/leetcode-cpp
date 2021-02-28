class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag;
        if (A[0] <= A[A.size()-1]) flag = 1;
        else flag = -1;
        return util(A, 1, flag);
    }
    bool util(vector<int>& A, int pos, int flag) {
        if (pos >= A.size()) return true;
        if (A[pos] == A[pos-1]) return util(A, pos+1, flag);
        int temp = A[pos] > A[pos-1] ? 1 : -1;
        if (temp == flag) return util(A, pos+1, flag);
        else return false;
    }
};
