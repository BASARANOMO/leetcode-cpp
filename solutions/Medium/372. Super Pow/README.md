# 372. Super Pow

## Solution1

Exponentiation by squaring (reverse traversal)

The distributive property of modulo:

`(a * b) mod m = [(a mod m) * (b mod m)] mod m`

Time complexity: `O(\sum_{i=0}^{m-1}log b_i)`, `m` is the length of the vector `b`

Space complexity: `O(1)`

## Solution2

Exponentiation by squaring (forward traversal)

Time complexity: `O(\sum_{i=0}^{m-1}log b_i)`, `m` is the length of the vector `b`

Space complexity: `O(1)`
