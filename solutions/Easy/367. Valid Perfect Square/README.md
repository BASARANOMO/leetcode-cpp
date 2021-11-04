# 367. Valid Perfect Square

## Solution1

Brute force

Time complexity: `O(sprt(n))`

## Solution2

Binary search

Time complexity: `O(log n)`

## Solution3

Newton's method

Time complexity: `O(log n)`

Each iteration can reduce the error between `x_i` and `num` to less than `1/4` of the original, so it only takes up to `log_4 m` to reduce the error to within the threshold range, where `m` is the ratio of the error between the initial value and `num` to the threshold.
