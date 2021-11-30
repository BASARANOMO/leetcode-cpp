# 519. Random Flip Matrix

## Solution1

Hashmap

Time complexity:

- `flip()`: `O(1)`
- `reset()`: `O(flipped time)`
  
Space complexity: `O(flipped time)`

## Solution2

K buckets

Time complexity:

- `flip()`: `O(sqrt(m * n))`
- `reset()`: `O(flipped time)`

Space complexity: `O(sqrt(m * n) + flipped time)`
