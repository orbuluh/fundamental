# KMP (Knuth–Morris–Pratt) algorithm for pattern matching
- [SRC: Tushar Roy - Coding Made Simple channel](https://youtu.be/GTJr8OvyEVQ)

# Key observation: "Redundant comparison if suffix equal to prefix"
- Say we have:
```
                  *
S = a b c V a b c X a b c V a b c Y
                  *
P = a b c V a b c Y
```
- when we compare X and Y, we realize it's not a match. And before Y, the sub-pattern `a b c V a b c` have a suffix `a b c` equal to its prefix `a b c`. What does this tells us?
- This would allow us to say that we can ignore to compare the prefix `a b c` again, we can just start to compare `X` and `V`, because we know in `S`, before `X` it's a `a b c`, and because prefix `a b c` in sub-pattern `P' = a b c V a b c` is the same as its suffix `a b c`, we can skip checking on those positions in the prefix.
```
                  *
S = a b c V a b c X a b c V a b c Y
          *
P = a b c V a b c Y
```
- And continue, when we compare `X` and `V`, we realize it's not equal. And before `V`, the sub-pattern is `P'' = a b c`, which doesn't have a prefix equal to its suffix - this would mean that we have to re-compare from the beginning in the next position.
```
                    *
S = a b c V a b c X a b c V a b c Y
    *
P = a b c V a b c Y
```
- and then we find a match at the end in this example.
- But the question is how do we efficiently find a "suffix equal to prefix" in the sub-pattern?

# Use 2 pointers to generate a lookup for "suffix equal to prefix" in the sub-pattern
- We will generate an array called `lps`, e.g. "Longest Prefix Suffix"
- The Pseudo code is:
```python
j = 0
lps = [0] * len(P)
for i in range(1, len(P)):
    while j > 0 and P[i] != P[j]:
        j = lps[j - 1];
    if P[i] == P[j]:
        lps[i] = ++j
```
- Imaging running the algorithm till we find `P[i] == P[j]` the first time:
```
      a b c V a b c Y
    i 0 1 2 3 4
    j 0 0 0 0 1
lps   0 0 0 0 1
```
- what does this mean? it means for situation like below, we find `Z` != `b`, and the sub-pattern `a b c V a` have a prefix `a` equal to suffix. Hence we know we can start comparison from index `lps[4] == 1` and continue.

<details><summary markdown="span">How the lps[i] is used:</summary>

```
              *
S = a b c V a Z .....
              *
P = a b c V a b c Y

--> at index 5, Z != b, and lps[4] == 1, so we compare P[1] with S[5]
              *
S = a b c V a Z .....
      *
P = a b c V a b c Y

--> at index 5, Z != b, and lps[1] == 0, so we compare P[0] with S[5]
              *
S = a b c V a Z .....
    *
P = a b c V a b c Y
--> at index 5, Z != b, and we know that we just can't find a match for S[5]
```
</details>


- Continue:
```python
j = 0
lps = [0] * len(P)
for i in range(1, len(P)):
    while j > 0 and P[i] != P[j]:
        j = lps[j - 1];
    if P[i] == P[j]:
        lps[i] = ++j
```
```
      a b c V a b c Y
    i 0 1 2 3 4 5 6 7
    j 0 0 0 0 1 2 3 ?
lps   0 0 0 0 1 2 3 ?

i == 7, j == 4, S[7] != S[4]
we make j = lps[i - 1] = lps[3] = 0
and because S[7] != S[0], lps[7] isn't update and has value 0
```

# Question set
- [:point_right: here](../substr_matching/README.md)
- implementation example check [:point_right: here](../substr_matching/max_len_of_repeated_subarray.h)