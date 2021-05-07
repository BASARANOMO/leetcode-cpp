# 137. Single Number II

## Solution1

Hash table

## Solution2

Bitwise operation

Time complexity: `O(n log C)`

### Solution3

Digital electronics simulation

We want to optimize the solution 2. Here we use two numbers `a` and `b`, and their `i`-th bit represent the number of occurrences of `1` on the `i`-th binary bit of all traversed numbers in the `list`.

Here is the truth table:

| `(a<sub>i</sub> b<sub>i</sub>)` | count of `1` on the `i`-th bit |
| :------------- | :------------- |
| 00 | 0 |
| 01 | 1 |
| 10 | 2 |
