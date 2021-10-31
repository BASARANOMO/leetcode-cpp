# 260. Single Number III

## Solution1

Hash table

Time complexity: `O(n)`

Space complexity: `O(n)`

## Solution2

Bitwise

`xorsum = x_1 ^ x_2`

`lowest bit of 1 = xorsum ^ -xorsum`

Two categories of numbers can be distinguished:

- Type1: numbers whose binary with `xorsum ^ -xorsum`-th bit being `1`
- Type2: numbers whose binary with `xorsum ^ -xorsum`-th bit being `0`
  
`x_1` and `x_2` must be in different categories, and numbers that appear twice must be in the same category.
