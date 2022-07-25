# Algorithm notes

## Binary search
- normally, use `std::binary_search`, `std::lower_bound`, `std::upper_bound` - check [notes :notebook:](https://github.com/orbuluh/cpp/blob/main/basics/binary_search.md)
- From the above 3 std functions, you can see there is 3 cases:
  - (1) `std::binary_search` - whether target exist
  - (2) `std::lower_bound` - what's the first occurrence of value >= target - e.g. **first occurrence** of target
  - (3) `std::upper_bound` - what's the first occurrence of value > target - e.g. previous is the **last occurrence** of target

### Implement by yourself
- The key to code binary search by yourselves is to **implement it as case (2) or (3), but not (1)**
  - e.g. **think binary search as a binary insert problem instead**
  - WHY? Because (2) or (3) has only one answer, while (1) could have multiple.
  - And because (1) could have multiple result, the implementation is easy to get wrong!
- So how to do it in binary insert way? - check [here :dart:](../binary_search/first_and_last_pos_of_tgt_in_arr.h)
#### Key 1: we want to make sure we don't go into infinite loop. How?
  - when you do `while (l < r)` ... and if ...
    - mid bias to `l`, e.g. `mid = l + (r - l) / 2`, then moving `r = mid` is guaranteed to be okay as `mid` can't equal to `r`
    - mid bias to `r`, e.g. `mid = l + (r - l + 1) / 2`, then moving `l = mid` is guaranteed to be okay as `mid` can't equal to `l`
  - when do we need to bias to `l`? When we try to find the first occurrence (case 2)
  - when do we need to bias to `r`? When we try to find the last occurrence (case 2)
#### Key 2: what to return?
  - when we bias to `l`, `mid` will eventually equal to `l` when loop break, which is the value we want to return.
  - vise-versa, when bias to `r`, we want to return `r`

## Dynamic programming
- DP's goal is finding **overlapping sub-problems** that can be memorized.
  - To memorize the sub-problems, each of them is basically a "DP state" (a.k.a optimal substructure), where the state is represented by parameters.
  - You need to think about what parameters could contribute a "unique" state.
  - The state, or the result of a subproblem should be unique:
    - It should not matter where you come from. If you reach state with specific set of parameters, the result is the same.
  - The main difference between DP and divide and conquer is that DP tries out multiple choices of smaller subproblems, subproblems generally recur across different recursive calls; In most divide-and-conquer algorithms, all the subproblems are distinct and there’s no point in caching their solutions.
- Another way to think about DP is: **Suppose someone handed us an optimal solution to us. What must it look like?**