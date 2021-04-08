class Solution {
public:
    int fib(int n) {
        int fib0 = 0, fib1 = 1, temp;
        while (n >  0) {
            temp = fib0 + fib1;
            fib0 = fib1;
            fib1 = temp;
            n--;
        }
        return fib0;
    }
};
