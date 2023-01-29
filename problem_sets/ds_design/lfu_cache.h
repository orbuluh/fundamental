/*
Requirements:
- remove least frequent one when full
- when full, and least freq has multiple, least recently used being invalidated
- When a key is first inserted into the cache, its use counter is set to 1
  (due to the put operation).
- The use counter for a key in the cache is incremented either a get or put
  operation is called on it.

- Not really O(1) for every operations below .. (though seems to be fast enough
  in result...). For O(1), need to be able to concatenate everything together so
  you can always get the head of the whole list as the one to be removed ...etc
*/

class LFUCache {
  struct KeyVal {
    int key = 0;
    int val = 0;
    int counter = 0;
  };
  std::set<int> nonEmptyFreq;
  std::unordered_map<int, std::list<KeyVal>> freq2KeyValList;
  using KeyValIter = std::list<KeyVal>::iterator;
  std::unordered_map<int, KeyValIter> keyVals;
  int capacity = 0;

 public:
  LFUCache(int c) : capacity(c) {}

  int get(int key) {
    auto it = keyVals.find(key);
    if (it == keyVals.end()) {
      return -1;
    }
    addCount(it->second);
    return it->second->val;
  }

  void put(int key, int value) {
    if (capacity <= 0) {
      return;
    }
    auto it = keyVals.find(key);
    if (it == keyVals.end()) {
      invalidate();
      freq2KeyValList[1].emplace_back(KeyVal{key, value, 1});
      keyVals[key] = std::prev(freq2KeyValList[1].end());
      nonEmptyFreq.insert(1);
    } else {
      addCount(it->second);
      it->second->val = value;
    }
  }
 private:
  void addCount(KeyValIter& iterToAddCnt) {
    auto& list1 = freq2KeyValList[iterToAddCnt->counter];
    auto& list2 = freq2KeyValList[++iterToAddCnt->counter];
    // move the element from list 1 to list 2
    list2.splice(list2.end(), list1, iterToAddCnt, std::next(iterToAddCnt));
    if (list1.empty()) {
      nonEmptyFreq.erase(iterToAddCnt->counter - 1);
    }
    nonEmptyFreq.insert(iterToAddCnt->counter);
  }

  void invalidate() {
    if (keyVals.size() < capacity) {
      return;
    }
    auto& leastFreqList = freq2KeyValList[*(nonEmptyFreq.begin())];
    auto leastUsedEleIt = leastFreqList.begin();
    const auto minFreq = leastUsedEleIt->counter;
    keyVals.erase(leastUsedEleIt->key);
    leastFreqList.erase(leastUsedEleIt);
    if (leastFreqList.empty()) {
      nonEmptyFreq.erase(minFreq);
    }
  }

  void print() const {
    for (const auto& p : freq2KeyValList) {
      std::cout << "freq=" << p.first << '\n';
      for (const auto& li : p.second) {
        std::cout << "\tkey=" << li.key << " val=" << li.val << '\n';
      }
    }
  }
};
