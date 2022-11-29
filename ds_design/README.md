# Data structure design

## [:ok_hand: 380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) [:dart:](insert_delete_get_random_o1.h)

<details><summary markdown="span">Question</summary>

```markdown
Implement the RandomizedSet class:

`RandomizedSet()`:
    Initializes the RandomizedSet object.
`bool insert(int val)`:
    Inserts an item val into the set if not present.
    Returns true if the item was not present, false otherwise.

`bool remove(int val)`:
    Removes an item val from the set if present.
    Returns true if the item was present, false otherwise.

`int getRandom()`:
    Returns a random element from the current set of elements
    (it's guaranteed that at least one element exists when this method is called).
    Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
```
</details>

------------------------------------------------------------------------------

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
