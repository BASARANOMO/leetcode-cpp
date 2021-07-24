# 1893. Check if All the Integers in a Range Are Covered

## Solution 1

Sort vector of vectors by first element (quite like the idea of greedy algorithm)

## Solution 2

Brute force

## Solution 3

Improved brute force

## Solution 4

Diff array + presum

`diff[i]++` means that the index `i` is covered by one range.

`diff[j + 1]--` means that the range ends at the index `j` (the index `j + 1` is not covered).

Then, the presum of `diff` is computed.

`presum[i] <= 0` means that the index `i` is __not__ covered by any range in `ranges`.
