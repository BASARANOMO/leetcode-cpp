# 137. Single Number II

## Solution1

Hash table

## Solution2

Bitwise operation

Time complexity: `O(n log C)`

### Solution3

Digital electronics simulation

We want to optimize the solution 2. Here we use two numbers `a` and `b`, and their `i`-th bit represent the reminder of the number of occurrences of `1` on the `i`-th binary bit of all traversed numbers in the `list` divided by `3`.

Here is the truth table:

| <code>(a<sub>i</sub> b<sub>i</sub>)</code> | count of `1` on the `i`-th bit |
| :------------- | :------------- |
| 00 | 0 |
| 01 | 1 |
| 10 | 2 |

When we traverse to a new integer `x`:

| <code>(a<sub>i</sub> b<sub>i</sub>)</code> | <code>x<sub>i</sub></code> | new <code>(a<sub>i</sub> b<sub>i</sub>)</code> |
| :------------- | :------------- | :------------- |
| 00 | 0 | 00 |
| 00 | 1 | 01 |
| 01 | 0 | 01 |
| 01 | 1 | 10 |
| 10 | 0 | 10 |
| 10 | 1 | 00 |

### Solution4

Optimization of solution 3
