# 470. Implement Rand10() Using Rand7()

## Solution

Rejection sampling

We can call 2 times `rand7()` (i.e. 1 round) and then multiply their returns to get a value in `[1, 49]`. When the value is no more than 40, we accept the result of sampling and use its index in a `7x7` matrix to generate random value in `[1, 10]` (uniform distribution with same probability for each value). When the value is in `[41, 49]`, we reject this round of sampling and restart.

Expectation of times of calling `rand7()`: 2.45

Improvement: When reject in the first round, we actually get a value in `[41, 49]` -> `[1, 9]`. Then we can call 1 more time `rand7()` (instead of 1 round) to get a value in `[1, 63]`. We accept it if the value in `[1, 60]` and then use the index of the value in a `9x7` matrix to generate random value in `[1, 10]`. If rejected, we get a value in `[61, 63]` -> `[1, 3]` and call 1 more time `rand7()`. The value now we have is in `[1, 21]`, we accept it if in `[1, 20]`. If rejected, we restart the whole process.

Expectation of times of calling `rand7()`: 2.19333
