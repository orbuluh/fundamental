# Data structure design
- more focus on insight of tree.
- For question that is more about beautiful recursion - check [notes :notebook:](../recursion/README.md)
- For segment tree - check [notes :notebook:](../range_query/segment_tree/README.md)

------------------------------------------------------------------------------

## [:bulb: 146. LRU Cache](https://leetcode.com/problems/lru-cache/) [:dart:](lru_cache.h)

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
