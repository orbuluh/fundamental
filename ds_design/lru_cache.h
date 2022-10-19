// 1. LRU is a cache of key value pair, so it's natural that there will be a map
//    like structure.
//
// 2. LRU needs to keep updating an element with latest usage - so you need
//    something that can be quick at insert and delete - therefore list comes to
//    mind. Imagine there is a list implying the usage of each key.
//
// think about the operations. When you get, you need a key to search the map.
// Then you need to update the key's timestamp to the latest. list won't have
// random access, so it's best that the map isn't just storing the value.
// Instead, map can store the iterator to the corresponding element in the list.
// By doing so, you can make change to the corresponding list element quickly.
// Also the get operation is checking on value, so what iterator point to should
// contain the value as well.
//
// When you put, you might need to clean up the stale element from the beginning
// of the list. Also, you would like to clean up the entry in the map. So you
// will need to store key information in list element as well.
//
// Combine above
// 1. the goal is creating a list where element is a key-value pair.
// 2. you don't need to store a timestamp because list ordering has implied.
// 3. the map will be key to iterator in the list
// 4. the (slightly) advanced part is list operations - particularly splice.
//

class LRUCache {
  struct KeyVal {
    int key = -1;
    int val = -1;
  };
  using TimedList = std::list<KeyVal>;
  TimedList timedVals_;
  std::unordered_map<int, TimedList::iterator> keyToIter_;
  int capacity_ = 0;

 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto it = keyToIter_.find(key);
    if (it == keyToIter_.end()) return -1;
    refresh(it->second);
    return it->second->val;
  }

  void refresh(TimedList::iterator itInTimedVals) {
    // refresh through moving to the end of list
    timedVals_.splice(timedVals_.end(), timedVals_, itInTimedVals);
  }

  void cleanupStale() {
    if (keyToIter_.size() <= capacity_) return;
    keyToIter_.erase(timedVals_.begin()->key);
    timedVals_.pop_front();
  }

  void put(int key, int value) {
    auto it = keyToIter_.find(key);
    if (it != keyToIter_.end()) {
      it->second->val = value;
      refresh(it->second);
    } else {
      timedVals_.emplace_back(KeyVal{key, value});
      // new element with max timestamp go to the back of list
      keyToIter_[key] = std::prev(timedVals_.end());
      cleanupStale();
    }
  }
};
