/*
At first glance, it seems that the ordering of removing stones matters. say
stones are

  4
1 2 3
  5

if you remove: [2 5 1]  --> 4 3 unremoved
But if you remove [4 5 1 3] --> only 2 unremoved

However, if you think the problem in another way ...

Say it's just counting connected component (CC), then it's a different story.
E.g. stones are in a CC iff they share either row or col indexes. Then the stone
you maximally can remove for a CC will be size(CC) - 1.

  4
1 2 3
  5
         6   7   8

---> 2 independent CC
     we can remove 4 stones from CC[1,2,3,4,5]
     we can remove 2 stones from CC[6,7,8]

At the end, total number of stones you can removed are sum(size(CC_i) - 1)
where CC_i is each of the connected component.


To find CC - how you dfs basically becomes counting the element in each
independent CC. E.g. for each dfs on a particular CC, you don't need to worry
the ordering, you just need to count how many stones are in this CC. And this
can be done through how many stones are removed after each dfs.

*/

class Solution {
 public:
  std::unordered_map<int, std::unordered_set<int>> rowMap;
  std::unordered_map<int, std::unordered_set<int>> colMap;
  std::bitset<1000> removed;
  int removeStones(vector<vector<int>>& stones) {
    const auto n = stones.size();
    for (int i = 0; i < n; ++i) {
      rowMap[stones[i][0]].insert(i);
      colMap[stones[i][1]].insert(i);
    }

    int removedCnt = 0;
    for (int i = 0; i < n; ++i) {
      if (removed.test(i)) {
        continue;
      }
      int beforeDfsCnt = removed.count();
      removed.set(i);
      removeConnectedStones(stones, i);
      removedCnt += (removed.count() - beforeDfsCnt - 1);
    }
    return removedCnt;
  }
  void removeConnectedStones(const vector<vector<int>>& stones, int idx) {
    int row = stones[idx][0];
    int col = stones[idx][1];
    // try to remove unremoved stones with same row
    for (int idx : rowMap[row]) {
      if (removed.test(idx)) {
        continue;
      }
      removed.set(idx);
      removeConnectedStones(stones, idx);
    }
    // try to remove unremoved stones with same col
    for (int idx : colMap[col]) {
      if (removed.test(idx)) {
        continue;
      }
      removed.set(idx);
      removeConnectedStones(stones, idx);
    }
  }
};