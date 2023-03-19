# Trie

## [:ok_hand: 208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree) / [:man_technologist:](implement_trie.h)

<details><summary markdown="span">Question</summary>

```markdown
A trie (pronounced as "try") or prefix tree is a tree data structure used to
efficiently store and retrieve keys in a dataset of strings.

Implement the Trie class:

`Trie()`
       - Initializes the trie object.
`void insert(String word)`:
       - Inserts the string word into the trie.
`boolean search(String word)`:
       - Returns true if the string word is in the trie (i.e., was inserted
         before), and false otherwise.
`boolean startsWith(String prefix)`
       - Returns true if there is a previously inserted string word that has the
       prefix prefix, and false otherwise.
```

</details>

------------------------------------------------------------------------------

## [211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure) / [:man_technologist:](design_add_and_search_ds.h)

<details><summary markdown="span">Question</summary>

```markdown
Design a data structure that supports adding new words and finding if a string
matches any previously added string.

Implement the WordDictionary class:

`WordDictionary()`
- Initializes the object.

`void addWord(word)`
- Adds word to the data structure, it can be matched later.

`bool search(word)`
- Returns true if there is any string in the data structure that matches word or
  false otherwise.
- word may contain dots '.' where dots can be matched with any letter.
```

</details>

------------------------------------------------------------------------------

## [:bulb: 212. Word Search II](https://leetcode.com/problems/word-search-ii/) / [:man_technologist:](word_search_ii.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.

The same letter cell may not be used more than once in a word.

Input: board = [["o","a","a","n"],
                ["e","t","a","e"],
                ["i","h","k","r"],
                ["i","f","l","v"]],
       words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

</details>

------------------------------------------------------------------------------

## [:dizzy_face: 336. Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/) / [:man_technologist:](palindrome_pair.h)

<details><summary markdown="span">Question</summary>

```markdown
You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:
- 0 <= i, j < word.length
- i != j, and
- words[i] + words[j] (the concatenation of the two strings) is a palindrome string.

Return an array of all the palindrome pairs of words.

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
```

</details>

------------------------------------------------------------------------------
