/*
O(n^2) find dependency, n is number of words
wrt v.s. wrf:    t < f
wrt v.s. er:     w < e
wrt v.s. rftt:   w < r
er  v.s. ett:    r < t
er  v.s. rftt:   e < r

graph:
t: [f]
w: [e, r]
r: [t]
e: [r]

topological sort O(26) = O(1)
- dfs[t]: res = [t, f]
- dfs[w]: res = [w, e, r, t, f]

Overall O(n^2)
*/

class Solution {
  std::unordered_set<char> allChars;
  std::unordered_map<char, std::unordered_set<char>> graph;
  bool foundCycle = false;

 public:
  string alienOrder(vector<string>& words) {
    if (!buildGraph(words)) {
      return "";
    }
    std::bitset<26> tempMark;
    std::bitset<26> permMark;
    std::list<char> result;
    for (char nodeChar : allChars) {
      if (!permMark.test(nodeChar - 'a')) {
        topoSort(nodeChar, tempMark, permMark, result);
      }
    }
    return foundCycle ? "" : std::string(result.begin(), result.end());
  }
  std::tuple<char, char, bool> firstDiff(std::string_view w1,
                                         std::string_view w2) {
    for (int i = 0; i < w1.size() && i < w2.size(); ++i) {
      if (w1[i] != w2[i]) {
        return {w1[i], w2[i], true};
      }
    }
    // Note: input could be ["abc", "ab"], but if it's sorted, it should have
    // been ["ab", "abc"] ... such case is just invalid ordering.
    return {' ', ' ', w1.size() <= w2.size()};
  }
  bool buildGraph(const vector<string>& words) {
    const auto n = words.size();
    for (int i = 0; i < n; ++i) {
      for (char c : words[i]) {
        allChars.insert(c);
      }
      for (int j = i + 1; j < n; ++j) {
        auto [c1, c2, valid] = firstDiff(words[i], words[j]);
        if (!valid) {
          return false;
        }
        if (c1 == ' ') {
          continue;
        }
        graph[c1].insert(c2);
      }
    }
    return true;
  }
  void topoSort(char nodeChar, std::bitset<26>& tempMark,
                std::bitset<26>& permMark, std::list<char>& result) {
    if (foundCycle) return;
    int charIdx = nodeChar - 'a';
    if (tempMark.test(charIdx)) {
      foundCycle = true;
      return;
    }
    tempMark.set(charIdx);
    for (char depChar : graph[nodeChar]) {
      if (permMark.test(depChar - 'a')) {
        continue;
      }
      topoSort(depChar, tempMark, permMark, result);
    }
    tempMark.reset(charIdx);
    permMark.set(charIdx);
    result.push_front(nodeChar);
  }
};