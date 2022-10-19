# Data structure design

## [:ok_hand: 692. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) [:dart:](top_k_freq_words.h)

<details><summary markdown="span">Question</summary>

```markdown
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest.
Sort the words with the same frequency by their lexicographical order.

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
             with the number of occurrence being 4, 3, 2 and 1 respectively.
```
</details>

------------------------------------------------------------------------------

## [:bulb::bulb: 146. LRU Cache](https://leetcode.com/problems/lru-cache/) [:dart:](lru_cache.h)

<details><summary markdown="span">Question</summary>

```markdown
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

`LRUCache(int capacity)`: Initialize the LRU cache with positive size capacity.
`int get(int key)`: Return the value of the key if the key exists, otherwise return -1.
`void put(int key, int value)`
- Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
- If the number of keys exceeds the capacity from this operation, evict the least recently used key.
- The functions get and put must each run in O(1) average time complexity.
```
</details>

------------------------------------------------------------------------------
