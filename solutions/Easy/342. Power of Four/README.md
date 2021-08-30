# 342. Power of Four

## Solution1

Bitwise operation like in the question [231. Power of Two](https://github.com/BASARANOMO/leetcode-cpp/tree/main/solutions/Easy/231.%20Power%20of%20Two)

If integer `n` is a power of four, then only the highest bit of its corresponding binary number is `1`, and the other bits are all `0`. In addition, the highest bit (which is `1`) should be the even bit (consider the lowest bit the 0th bit).

## Solution2

Bitwise operation + modulo operation

If integer `n` is a power of four, the reminder of dividing it by `3` must be `1`.

If integer `n` is a power of two but not a power of four, the reminder of dividing it by `3` should be `2`.
