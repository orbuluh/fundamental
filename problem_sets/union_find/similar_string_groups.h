bool isSimilar(std::string_view a, std::string_view b) {
  int diff = 0;
  for (int i = 0; i < a.size() && diff <= 3; ++i) {
    diff += a[i] != b[i];
  }
  return diff <= 2;
}

class Solution {
 public:
  class DisjoinSet {
    std::vector<int> parents;
    std::vector<int> groupsSz;
    int sz = 0;
   public:
    DisjoinSet(int n) : sz(n) {
      parents.resize(n);
      groupsSz = std::vector<int>(n, 1);
      std::iota(parents.begin(), parents.end(), 0);
    }

    int findParent(int x) {
      if (parents[x] == x) {
        return x;
      }
      return parents[x] = findParent(parents[x]);
    }

    void join(int a, int b) {
      int x = findParent(a);
      int y = findParent(b);
      if (x != y) {
        sz--;
        // always merge smaller group to larger one so that the depth of merged
        // groups is likely to be smaller
        if (groupsSz[x] > groupsSz[y]) {
          std::swap(x, y);
        }
        parents[x] = y; // smaller group's parent assign to larger group
        groupsSz[y] += groupsSz[x];
      }
    }

    int size() const { return sz; }
  };

  int numSimilarGroups(vector<string>& strs) {
    const int sz = strs.size();
    DisjoinSet dj(sz);

    for (int i = 0; i < sz - 1; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        if (isSimilar(strs[i], strs[j])) {
          dj.join(i, j);
        }
      }
    }

    return dj.size();
  }
};