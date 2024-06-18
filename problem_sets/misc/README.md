# Misc

## Good for practice

## [:ok_hand: 43. Multiply Strings](https://leetcode.com/problems/multiply-strings) / [:snake:](multiply_strings.py)

<details><summary markdown="span">Question</summary>

```markdown
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 71. Simplify Path](https://leetcode.com/problems/simplify-path) / [:man_technologist:](simplify_path.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a string path, which is an absolute path (starting with a slash '/') to
a file or directory in a Unix-style file system, convert it to the simplified
canonical path.

In a Unix-style file system,
- a period '.' refers to the current directory,
- a double period '..' refers to the directory up a level, and
- any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.

For this problem, any other format of periods such as '...' are treated as
file/directory names.

The canonical path should have the following format:

- The path starts with a single slash '/'.
- Any two directories are separated by a single slash '/'.
- The path does not end with a trailing '/'.
- The path only contains the directories on the path from the root directory to the target file or directory (i. e., no period '.' or double period '..')

Return the simplified canonical path.


Input: path = "/home/"
Output: "/home"

Input: path = "/../"
Output: "/"

Input: path = "/home//foo/"
Output: "/home/foo"
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 348. Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe) / [:snake:](tic_tac_toe.py)

<details><summary markdown="span">Question</summary>

```markdown
Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move, and the two players alternate in making moves. Return
0 if there is no winner after the move,
1 if player 1 is the winner after the move, or
2 if player 2 is the winner after the move.


Example 1:

Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]
```

</details>

------------------------------------------------------------------------------

## Great algo to do something

## [:ok_hand: 916. Word Subsets](https://leetcode.com/problems/word-subsets/) / [:man_technologist:](word_subsets.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two string arrays words1 and words2.
- A string b is a **subset** of string a if
  every letter in b occurs in a including multiplicity.
- For example, "wrr" is a subset of "warrior" but is not a subset of "world".

- A string a from words1 is **universal** if
  for every string b in words2, b is a subset of a.

- Return an array of all the universal strings in words1.
  You may return the answer in any order.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 334. Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) / [:man_technologist:](inc_triplet_subseq.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an integer array nums
return true if there exists a triple of indices (i, j, k) such that
- i < j < k and
- nums[i] < nums[j] < nums[k].

If no such indices exists, return false.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 249. Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/) / [:man_technologist:](group_shifted_strings.h)

- asked in peer mock, how to hash the input is actually easy but you complicated it...

<details><summary markdown="span">Question</summary>

```markdown
We can shift a string by shifting each of its letters to its successive letter.
- For example, "abc" can be shifted to be "bcd" and "za" could shift to "ab"

We can keep shifting the string to form a sequence.
- For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".

Given an array of strings strings, group all strings[i] that belong to the same shifting sequence.
You may return the answer in any order.

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 1470. Shuffle the Array](https://leetcode.com/problems/shuffle-the-array) / [:man_technologist:](shuffle_array.h)

<details><summary markdown="span">Question</summary>

- Challenge: how to do it in-place without extra memory?

```markdown
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Note: 1 <= nums[i] <= 10^3

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 189. Rotate Array](https://leetcode.com/problems/rotate-array/) / [:man_technologist:](rotate_array.h)

<details><summary markdown="span">Question</summary>

- "How to rotate 1" is actually interesting than you think ... give it a try!

```markdown
Given an array, rotate the array to the right by k steps, where k is non-negative.

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 833. Find And Replace in String](https://leetcode.com/problems/find-and-replace-in-string/) / [:man_technologist:](find_and_replace_in_string.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed string s that you must perform k replacement
operations on. The replacement operations are given as three 0-indexed parallel
arrays, all of length k:
- indices
- sources
- targets

To complete the ith replacement operation:

- Check if the substring sources[i] occurs at index indices[i] in the original
string s. If it does not occur, do nothing. Otherwise if it does occur, replace
that substring with targets[i].

For example, if
- s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] = "eee",
- then the result of this replacement will be "eeecd".

All replacement operations must occur simultaneously, meaning the replacement
operations should not affect the indexing of each other.

The testcases will be generated such that the replacements will not overlap.

For example, a test-case with s = "abc", indices = [0, 1], and
sources = ["ab","bc"] will not be generated because the "ab" and "bc"
replacements overlap. Return the resulting string after performing all
replacement operations on s.

A substring is a contiguous sequence of characters in a string.
</details>

------------------------------------------------------------------------------

## [:bulb: 1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) / [:man_technologist:](remove_adj_dups_ii.h)
<details><summary markdown="span">Question</summary>

```markdown
You are given a string s and an integer k,
- a k duplicate removal
    - consists of choosing k adjacent and equal letters from s and removing them
    - causing the left and the right side of the deleted substring to concatenate together.

- We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.
It is guaranteed that the answer is unique.

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
- First delete "eee" and "ccc", get "ddbbbdaa"
- Then delete "bbb", get "dddaa"
- Finally delete "ddd", get "aa"
```

</details>

------------------------------------------------------------------------------

## [:persevere: 2444. Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds) / [:man_technologist:](count_subarrays_with_fixed_bounds.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 2306. Naming a Company](https://leetcode.com/problems/naming-a-company) / [:man_technologist:](naming_a_company.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an array of strings ideas that represents a list of names to be
used in the process of naming a company.

The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name
ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a
valid company name. Otherwise, it is not a valid name.

Return the number of distinct valid names for the company.

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/) / [:man_technologist:](score_of_parentheses.h)

- the more intuitive way to do this ... though also not as easy as you think ... [stack solution](score_of_parentheses_stack_sol.h)

<details><summary markdown="span">Question</summary>

```markdown
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.

Input: s = "(())"
Output: 2

Input: s = "()()"
Output: 2
```

</details>

------------------------------------------------------------------------------

## Nice implementation idea

## [:ok_hand: 1539. Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number) / [:man_technologist:](kth_missing_positive_number.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array arr of positive integers sorted in a strictly increasing order,
and an integer k.

Return the kth positive integer that is missing from this array.

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...].
             The 5th missing positive integer is 9.

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...].
             The 2nd missing positive integer is 6.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/) / [:man_technologist:](integer_to_roman.h)

<details><summary markdown="span">Question</summary>

```markdown
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example,
- 2 is written as II in Roman numeral, just two one's added together.
- 12 is written as XII, which is simply X + II.
- he number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.
```

</details>

------------------------------------------------------------------------------

## [:ok_hand: 443. String Compression](https://leetcode.com/problems/string-compression) / [:man_technologist:](string_compression.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be
stored in the input character array chars.

Note that group lengths that are 10 or longer will be split into multiple
characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be:
       ["a","2","b","2","c","3"]
```

</details>

------------------------------------------------------------------------------

## Hard indices manipulation

## [:bulb: 48. Rotate Image](https://leetcode.com/problems/rotate-image/) / [:man_technologist:](rotate_image.h)

- TODO: dig in optimal solution [here](rotate_image_optimal.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given an n x n 2D matrix representing an image,
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly.

DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

</details>

------------------------------------------------------------------------------

## [:persevere: 6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion) / [:man_technologist:](zigzag_conversion.h)

<details><summary markdown="span">Question</summary>

```markdown
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this:

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

</details>

------------------------------------------------------------------------------

## [:persevere: 835. Image Overlap](https://leetcode.com/problems/image-overlap/) / [:man_technologist:](image_overlap.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given two images, img1 and img2,
- represented as binary, square matrices of size n x n.
- A binary matrix has only 0s and 1s as values.

We translate one image however we choose by
- sliding all the 1 bits left, right, up, and/or down any number of units.

We then place it on top of the other image.

We can then calculate the overlap by counting the number of positions that have
a 1 in both images.

Note also that a translation does not include any kind of rotation.

Any 1 bits that are translated outside of the matrix borders are erased.
Return the largest possible overlap.

Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: making a right shift then down shift of img1 - it becomes
[[0,0,0],[0,1,1],[0,0,1]], which has 3 overlap with img2
```

</details>

------------------------------------------------------------------------------

## Brainteaser

## [:bulb: 458. Poor Pigs](https://leetcode.com/problems/poor-pigs) / [:man_technologist:](pool_pigs.h)

<details><summary markdown="span">Question</summary>

```markdown
There are buckets buckets of liquid, where exactly one of the buckets is poisonous.
To figure out which one is poisonous,
you feed some number of (poor) pigs the liquid to see whether they will die or not.

Unfortunately, you only have minutesToTest minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

- Choose some live pigs to feed.
- One pig can drink several buckets in each test round simultaneously and will take no time.
- Several pigs can drink the same buckets in each test round.
- Wait for minutesToDie minutes. You may not feed any other pigs during this time.
- After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
- Repeat this process until you run out of time.

Given buckets, minutesToDie, and minutesToTest,
return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.

Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2

Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 932. Beautiful Array](https://leetcode.com/problems/beautiful-array/) / [:man_technologist:](beautiful_array.h)

- or math/divide conquer? It's ridiculous to find such solution ...

<details><summary markdown="span">Question</summary>

```markdown
An array nums of length n is beautiful if:

nums is a permutation of the integers in the range [1, n].

- For every 0 <= i < j < n, there is no index k with i < k < j
  where `2 * nums[k] == nums[i] + nums[j]`.

Given the integer n, return any beautiful array nums of length n.
There will be at least one valid answer for the given n.

Input: n = 4
Output: [2,1,4,3]

Input: n = 5
Output: [3,1,2,5,4]

Input: n = 6
Output: [1,5,3,2,6,4]
```

</details>

------------------------------------------------------------------------------
