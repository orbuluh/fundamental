# Data structure design


## [:ok_hand: 232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) / [:man_technologist:](implement_queue_using_stacks.h)

- The idea of only move element once between stack is brilliant! Almost brain teaser like.

<details><summary markdown="span">Question</summary>

```markdown
Implement a first in first out (FIFO) queue using only two stacks.

The implemented queue should support all the functions of a normal queue
(push, peek, pop, and empty).

Implement the MyQueue class:

- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns true if the queue is empty, false otherwise.
```
</details>

------------------------------------------------------------------------------

## [:ok_hand: 380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) / [:man_technologist:](insert_delete_get_random_o1.h)

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

## [:ok_hand: 692. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) / [:man_technologist:](top_k_freq_words.h)

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

## [:ok_hand: 2336. Smallest Number in Infinite Set](https://leetcode.com/problems/smallest-number-in-infinite-set) / [:man_technologist:](smallest_number_in_inf_set.h)

<details><summary markdown="span">Question</summary>

```markdown
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

`SmallestInfiniteSet()`

- Initializes the SmallestInfiniteSet object to contain all positive integers.

`int popSmallest()`

- Removes and returns the smallest integer contained in the infinite set.

`void addBack(int num)`

- Adds a positive integer num back into the infinite set, if it is not already
  in the infinite set.

Input
["SmallestInfiniteSet",
 "addBack",       // 2 is already in the set, so no change is made
 "popSmallest",   // 1 is the smallest number, 2 to inf remain
 "popSmallest",   // 2 is the smallest number, 3 to inf remain
 "popSmallest",   // 3 is the smallest number, 4 to inf remain
 "addBack",       // 1, 4 to inf remain
 "popSmallest",   // 1 is the smallest number, 4 to inf remain
 "popSmallest",   // 4 is the smallest number, 5 to inf remain
 "popSmallest"]   // 5 is the smallest number, 6 to inf remain
[[],    [2], [], [], [], [1], [], [], []]
Output
[null, null, 1,   2, 3, null, 1,   4, 5]
```

</details>

------------------------------------------------------------------------------

## [:bulb: 460. LFU Cache](https://leetcode.com/problems/lfu-cache/) / [:man_technologist:](lfu_cache.h)

<details><summary markdown="span">Question</summary>

```markdown
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

- `LFUCache(int capacity)`
  - Initializes the object with the capacity of the data structure.
- `int get(int key)`
  - Gets the value of the key if the key exists in the cache.
  - Otherwise, returns -1.
`void put(int key, int value)`
  - Update the value of the key if present, or inserts the key if not already
    present.
  - When the cache reaches its capacity, it should invalidate and remove the
    least frequently used key before inserting a new item.
  - For this problem, when there is a tie (i.e., two or more keys with the same
    frequency), the least recently used key would be invalidated.

- To determine the least frequently used key, a use counter is maintained for
  each key in the cache. The key with the smallest use counter is the least
  frequently used key.

- When a key is first inserted into the cache, its use counter is set to 1 (due
  to the put operation).
- The use counter for a key in the cache is incremented either a get or put
  operation is called on it.
- The functions get and put must each run in O(1) average time complexity.

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[      [2], [1, 1], [2, 2], [1], [3, 3], [2],    [3],  [4, 4], [1],   [3],   [4]]
Output
[     null, null,    null,   1,   null,   -1,      3,     null, -1,    3,     4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
```
</details>

------------------------------------------------------------------------------
## [:persevere: 146. LRU Cache](https://leetcode.com/problems/lru-cache/) / [:man_technologist:](lru_cache.h)

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
