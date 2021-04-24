# 363. Max Sum of Rectangle No Larger Than K

[LeetCode-cn](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)

## Solution

- Enumerate the upper and lower boundaries of the rectangle
- Enumerate the right boundary of the rectangle
- Make use of `set` to quickly locate the left boundary of the rectangle

Improvement: if `number of rows > number of columns` of the input `matrix`, we can do this in the other direction (from left to right then from up to down)
