# 1337. The K Weakest Rows in a Matrix

## Solution

Priority queue + binary search

Time complexity: `O(m log n + m log m + k log m)`

## Solution bis

Priority queue + binary search

Improvement: build the priority queue in `O(m)`

Time complexity: `O(m log n + m + k log m)`

## Solution2

Binary search + quick select
