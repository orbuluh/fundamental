# Binary search

Normally, use `std::binary_search`, `std::lower_bound`, `std::upper_bound` - check [notes :notebook:](https://github.com/orbuluh/cpp/blob/main/notes/binary_search.md)

From the above 3 std functions, you can see there is 3 cases:

- (1) `std::binary_search` - whether target exist
- (2) `std::lower_bound` - what's the first occurrence of value >= target - e.g. **first occurrence** of target
- (3) `std::upper_bound` - what's the first occurrence of value > target - e.g. previous is the **last occurrence** of target

## Keys to implement by yourself

- Why std have 3 versions? It turns out the key to implement binary search by yourselves is to **implement it as if case (2) or (3), but not (1)** E.g. **think binary search as a binary insert problem instead**
- :bulb: WHY? Because (2) or (3) has only one answer, while (1) could have multiple.
- :bulb: And because (1) could have multiple result, the implementation is easy to get wrong!
- So how to do it in binary insert way? - check [implementation here](../problem_sets/binary_search/first_and_last_pos_of_tgt_in_arr.h) and below reasoning.

### Key 1: Think about your goal first, are you dealing with case (2) or case (3)?

Generally for binary search, you know that

- **[Rule.Gen.1]**: In each iteration, one of either `l` or `r` should be moved, otherwise you will get infinite loop.
- **[Rule.Gen.2]**: When `nums[mid] > target`, you want to move `r`, and when `nums[mid] < target`, you want to move `l`. But how? Depends on your goal.

:one: When the goal is finding **"the first"** occurrence of `target`

- What's the key of finding "the first occurrence"? If `nums[mid] == target`, you want to make `mid` a right boundary of the answer. (Answer cannot be on mid's right hand side, but answer could be on its left hand side, as there could be multiple value equal to target, and you are trying to find "the first")
- And because `mid` is now the right bound, you know that you want to make `r = mid`. So overall you want to do: `r = mid` when `value >= target` (adding `>` in condition because **[Rule.Gen.2]**)
- And because **[Rule.Gen.1]**, you know that you must make `l = mid + 1` when `value < target`, otherwise you are getting infinite loop. Exam further, it makes sense as whenever `nums[mid] < target`, `mid` just can't be the first occurrence of `target`
- Or you can think this in another way - we are finding first occurrence, so whenever `value < target`, `mid` can't be an answer and it's too small, so we can safely move left bound using `l = mid + 1`.

:two: When the goal is finding **"the last"** occurrence of `target`

- What's the difference of finding "the last" occurrence? If `nums[mid] == target`, you want to make `mid` a left boundary of the answer instead, as you want to find the last. So this is a condition when you set up `l`
- So again, because **[Rule.Gen.2]**, you want to do `l = mid` when `value <= target`
- Also again, because **[Rule.Gen.1]**, you know that you should do `r = mid - 1` when `value > target`. Check further, if `nums[mid] > target`, it just can never be the last occurrence of the `target`, so we are good here.
- Same, you can think this in another way - we are finding last occurrence, so whenever `value > target`, `mid` can't be an answer and it's too big, so we can safely move right bound using `r = mid - 1`.

### Key 2: Keep the invariance `l != r` inside the iteration

- E.g. Always making `while (l < r)` as the loop condition.
- With this invariance, you don't need to deal with the edge case that `l == r` inside the iteration.

### Key 3: Based on how you move 2 pointers, decide how you compute `mid` to avoid infinite loop

Summary of key 1:

```txt
# Finding first occurrence:
    if nums[mid] >= target: r = mid
    else: l = mid + 1

# Finding last occurrence:
    if nums[mid] <= target: l = mid
    else: r = mid + 1
```

- So you can see, in either case, you could not move `r` or not move `l` in an iteration.
- From Key 2, you know that inside your loop, you are sure `l != r`, but what if `r == mid` when finding first occurrence or `l == mid` when finding last occurrence? You could have hit infinite loop!
- How to avoid? For finding the first occurrence, because you could do `r = mid` - you just need to make sure `mid` can never equal to `r`. How? You need to make `mid` calculation "left-bias". How? `mid = l + (r - l) / 2`, so when `r == l + 1`, `mid` can only equal to `l`.
- Similarly, you should do "right-bias" when finding last occurrence, e.g. `mid = l + (r - l + 1) / 2`, then moving `l = mid` is guaranteed to be okay as `mid` can't equal to `l`


### Key 4: what to return?

- when we bias to `l`, `mid` will eventually equal to `l` when loop break, which is the value we want to return.
- vise-versa, when bias to `r`, we want to return `r`

### Conclusion

```cpp
  int firstOccur(const vector<int>& nums, int l, int r, int target) {
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }

  int lastOccur(const vector<int>& nums, int l, int r, int target) {
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (nums[mid] <= target) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }
```