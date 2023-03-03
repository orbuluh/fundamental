# Substring matching: KMP (Knuth–Morris–Pratt) algorithm for pattern matching

- [SRC: Tushar Roy - Coding Made Simple channel](https://youtu.be/GTJr8OvyEVQ)

- The normal BF solution for substring matching is trying to search from each `i` where `S[i] == P[0]`, and then compare the substring. So this basically takes `O(size(S) * size(P))`

> :brain::bulb: KMP key observation: "Redundant comparison happens if suffix equal to prefix"

Say we have: `S = abcVabcXabcVabcY`, `P = abcVabcY`.

```txt
idx:0 1 2 3 4 5 6 7 8 9 ..........
                  *                    i = 7
S = a b c V a b c X a b c V a b c Y
                  *
P = a b c V a b c Y                    j = 7
    |_____P'____|
```

> Notation below `S[m:n]` isn't python - I mean substring including `S[n]`.

- Say we keep 2 pointers `i` and `j`. Where `i` is index on `S` and `j` is index on `P`.
- At `i = 7 and j = 7`, we find a mismatch `X` and `Y`. Normally, the BF solution is
  - reset `j = 0` and `i = 4` (as `S[4]` is the first index equal to `P[0]` again)
- The key point for KMT is that we might not need to start over, as long as redundant comparison exists. What is redundant comparison?
  - `S[4:6]` is equal to `P[0:2]` when we do the BF solution.
  - But because `P[4:6]` equals to `P[0:2]`, which equals to `S[4:6]`, we don't really need to compare `S[4:6]` with `P[0:2]` again.
  - Rather, we could have reset `j = 3` and we don't even need to move `i`
- The above can be done because the fact that `P[0:2] == P[4:6] == S[4:6]`, e.g. for sub-pattern `P' = P[0:6] = a b c V a b c`, it has a suffix `P[4:6] = a b c` equal to its prefix `P[0:2] = a b c`.

```txt
idx:0 1 2 3 4 5 6 7 8 9 ..........
                  *                  i = 7
S = a b c V a b c X a b c V a b c Y
          *                          j = 3 (didn't reset to 0, as we know S[4:6] == P[0:2])
P = a b c V a b c Y
    |P''|
```

- Continue, when we compare `S[7] = X` and `P[3] = V`, it's still a mismatch. And before `P[3]`, the sub-pattern is `P'' = a b c`, which doesn't have a prefix equal to its suffix - this would mean that we have no redundant comparison to save this time. The `S[7] = X` just simply can't be a submatch of any portion of `P`. So we can move on to set `i = 8` and `j = 0`


```txt
idx:0 1 2 3 4 5 6 7 8 9 ..........
                    *                i = 8
S = a b c V a b c X a b c V a b c Y
    *                                j = 0
P = a b c V a b c Y
```

So overall, we want to pre-compute such "prefix == suffix" information in `P`, so that we know when the redundant comparison happens. But how?

- We will generate an array called `lps` (a.k.a "Longest Prefix Suffix"), which have same length as `P`. (Or say, it's a "partial match table".
- `lps[j]` tells us the information:
  - When a mismatch happens at j (in `P`), it should imply `P[0:j-1]` is still a match with substring ended at `S[i-1]`
  - and if `P[0:j-1]` have suffix with len `x` equals to prefix, then we can simply reset j to `x`, as `P[0:x-1]` must match the substring ended at `S[i-1]`. And when we do so, we don't need to reset `i` at all, and overall we skip the redundant comparison as a result.
- We can imagine ...
  - Before finding any prefix == suffix, lps[j] should equal to 0
  - lps[0] must be 0 as single char can't have prefix == suffix
  - Once we find a match of prefix == suffix, we basically grow the length
  - Overall it should look like:

```txt
     0 1 2 3 4 5 6 7
  P: a b c V a b c Y
lcs: 0                --> substring "a" has no prefix == suffix
       0              --> substring "ab" has no prefix == suffix
         0            --> substring "abc" has no prefix == suffix
           0          --> substring "abcV" has no prefix == suffix
             1        --> substring "abcVa" has prefix "a" == suffix
               2      --> substring "abcVab" has prefix "ab" == suffix
                 3    --> substring "abcVabc" has prefix "abc" == suffix
                   0  --> substring "abcVabcY" has no prefix == suffix
```

- The Pseudo code is:

```python
j = 0
lps = [0] * len(P)
for i in range(1, len(P)):
    while j > 0 and P[i] != P[j]:
        j = lps[j - 1]
    if P[i] == P[j]:
        lps[i] = ++j
```

For example:

```txt
idx 0 1 2 3 4 5
              *       i = 5
S = a b c V a Z .....
              *       j = 5
P = a b c V a b c Y
lps 0 0 0 0 1 2 3 0

--> at index 5, Z != b, and lps[4] == 1, so we reset j = 1, keep i = 5

idx 0 1 2 3 4 5
              *       i = 5
S = a b c V a Z .....
      *               j = 1
P = a b c V a b c Y
lps 0 0 0 0 1 2 3 0

--> at index 5, Z != b, and lps[1] == 0, so we reset j = 0, keep i = 5
              *
S = a b c V a Z .....
    *
P = a b c V a b c Y
lps 0 0 0 0 1 2 3 0
--> at index 5, Z != b, and we know that we just can't find a match for S[5]
```

**Question set**

- The pure "just use KMP" implementation [:point_right: here](../problem_sets/substr_matching/find_first_occurrence_in_string.h)
- Other KMP question[:point_right: here](../problem_sets/substr_matching/README.md)
