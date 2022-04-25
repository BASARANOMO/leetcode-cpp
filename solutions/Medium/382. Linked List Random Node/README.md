# 382. Linked List Random Node

## Solution1

Reservoir sampling

Time complexity:
    - Initialization `O(1)`
    - getRandom() `O(n)`

Space complexity: `O(1)` make use of reference declaration (C++)

## Solution2

Turn the linked list into a vector

Time complexity:
    - Initialization `O(n)`
    - getRandom() `O(1)`

Space complexity: `O(n)`
