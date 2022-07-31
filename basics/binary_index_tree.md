# Binary indexed tree
- a.k.a Fenwick Tree
- Taking notes from:
  - [Chandan Mittal](https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/)
  - [WilliamFiset YT](https://youtu.be/BHPez138yX8)
  - [Malomalomalomalo's blog](https://codeforces.com/blog/entry/57292)

## Basic idea
- For a given array of size N, we can maintain an array BIT[] such that, at any index we can store sum of some numbers of the given array.
- BITs take advantage of the fact that **ranges can be broken down into other ranges, and combined quickly**.
- Basically, if we can precalculate the range query for a certain subset of ranges, we can quickly combine them to answer any [1,x] range query.

## The "binary indexed"
- The clever way of utilizing the array index to represent "range"
- For index i,
  - the least significant bit (LSB) of i represents the length of the range
  - Specifically: the index is responsible for LSB(i) range below itself
  - This is the critical part to form the range query, check [session below](#query-the-tree)
  - (check [graph below](#overall-structure))
- (We exclude zero as its binary representation doesn't have any ones. So LSB pattern above doesn't apply.)

- For examples:
  - index 1 (001) has LSB at 1, range length: 1. So it covers previous 1 element, range [1 - 1 + 1, 1] = [1, 1]
  - index 2 (010) has LSB at 2, range length: 2. So it covers previous 2 elements, range [2 - 1 + 1, 2] = [1, 2]
  - index 3 (011) has LSB at 1, range length: 1. So it covers previous 1 element, range [3 - 1 + 1, 3] = [3, 3]
  - index 4 (100) has LSB at 4, range length: 4. So it covers previous 4 elements, range [4 - 4 + 1, 4] = [1, 4]
  - index 5 (101) has LSB at 1, range length: 1. So it covers previous 1 element, range [5 - 1 + 1, 5] = [5, 5]
  - index 6 (110) has LSB at 2, range length: 2. So it covers previous 2 elements, range [6 - 2 + 1, 6] = [5, 6]
  - index 7 (111) has LSB at 1, range length: 1. So it covers previous 1 element, range [7 - 1 + 1, 7] = [7, 7]

- Generalize: at BIT[i] stores the cumulative sum from the index [i - lsb(i) + 1, i]  (both inclusive).

### Trick to isolate the least significant bit: `x & (-x)`

<details><summary markdown="span">Proof</summary>

- Say `x = a1b` (in binary) is the number whose least significant bit we want to isolate.
  - `a` is some binary sequence of any length of 1’s and 0’s and
  - `b` is some sequence of any length but of **0’s only**.
  - That tiny intermediate 1 bit sitting between **a** and **b** to be the least significant bit
- Then
```
-x = 2’s complement of x = (a1b)’ + 1
   = a’0b’ + 1
   = a’0(0...0)’ + 1
   = a’0(1...1) + 1
   = a’1(0...0)
   = a’1b
```
- Then
```
        a  1 b     ->  X
&       a' 1 b     -> -X
-----------------
=  (0...0) 1 (0...0)   ---> e.g. we get the LSB through X & (-x)
```

</details>


## Overall structure
- Space Complexity: O(N) for declaring another array of size N
- Implementation details check [this question :dart:](../range_query/binary_indexed_tree/range_sum_query_mutable_binary_indexed_tree.h)
  - Some details about how we ignore index 0, and how to construct/update.
![](../srcs/binary_index_tree.png)

## Construct the tree
- When you update a range includes [i, j] (inclusive), you will need to update range that includes [i, j] as well.
- But how? When you update BST[i], you can find the next affected range BST[j] through
  - `j = i + LSB(i)`
```cpp
void update(int x, int valDelta) {
    for (; x <= n; x += (x & -x)) { // keep adding LSB(x) till exceed
        BIT[x] += valDelta;
    }
}
```
- Implementation details check: [this question :dart:](../range_query/binary_indexed_tree/range_sum_query_mutable_binary_indexed_tree.h)

## Query the tree
- Recall that BST[i] is responsible for range i and LSB(i) range below i.
  - For example, BST[10] has LSB(10) = 2, so BST[10] take care of range [9, 10]
- Say we want to query Range(1, x), then the algorithm would basically be:
```cpp
int query(int x) // returns the sum of first x elements in given array a[]
{
    int sum = 0;
    for (; x > 0; x -= (x & -x)) // e.g. keep resetting LSB(x)
        sum += BIT[x];
    return sum;
}
```
- e.g. query(1, 10) = BST[10] + BST[8]
  - LSB(10) = 2, so next we find LSB(10 - 2), e.g. 8
  - LSB(8) = 8, so next we find LSB(8 - 8) = 0. e.g. loop finish
- the loop iterates at most the number of bits in x, so the query operation takes O(log2(n))
- Implementation details check: [this question :dart:](../range_query/binary_indexed_tree/range_sum_query_mutable_binary_indexed_tree.h)


##  The "binary indexed" property
- With how the index is used to represent a range, it can be proved that ...
  - (P.1) Every range [1,x] is constructable from the intervals given
  - (P.2) Every range decomposes into at most log N ranges.
  - (P.3) Every index is included by at most log N intervals.
- Proof listed in  [article](https://codeforces.com/blog/entry/57292)
