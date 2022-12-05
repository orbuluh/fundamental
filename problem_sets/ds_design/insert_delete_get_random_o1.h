/*
The slight tricky thing to do is since you need random access, you want a vector
to store all the value. You can keep a map to find a number in the vector, but
what about when some element is removed?

The aha is that when you remove, you swap the last element to the deleted
location. By doing so, all the other indexes are good after the deleted one.
And you can still O(1) randomly pick up a value in the vector!

Side note: although rand() is generally not encouraged to be random enough per
stackoverflow ... it's much faster in OJ and seems to be random enough.
*/

class RandomizedSet {
  std::vector<int> allVals;
  std::unordered_map<int, int> valIdxMap;

 public:
  bool insert(int val) {
    auto res = valIdxMap.emplace(val, allVals.size());
    if (res.second) {
      allVals.push_back(val);
      return true;
    }
    return false;
  }

  bool remove(int val) {
    auto it = valIdxMap.find(val);
    if (it != valIdxMap.end()) {
      auto deleteValIdx = it->second;
      auto lastVal = allVals.back();
      valIdxMap[lastVal] = deleteValIdx;
      allVals[deleteValIdx] = lastVal;
      allVals.pop_back();
      valIdxMap.erase(it);
      return true;
    }
    return false;
  }

  int getRandom() {
    // static std::random_device randDev;
    // static std::mt19937 generator(randDev());
    // std::uniform_int_distribution<int> distr(0, allVals.size() - 1);
    // return allVals[distr(generator)];
    return allVals[rand() % allVals.size()];
  }
};
