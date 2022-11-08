/*
The reversed indexes approach:

Make a char to indicies map. And basically keep a record of your current index
on the source string. Whenever you find that for a character, it's appearing
index is already after your tracking of current source string, it means you need
to find subsequence again from the beginning.

As you build the indices in O(n), then the finding indicies of certain char can
be done using binary search, you take O(n) + O(m * log(n)) where n is len of
source and m is len of target.

(Note theoretically faster than approach but actually slower in OJ)

For example:

source = "xyzyx", target = "xzyxzzx"

indicies map:
x: [0, 4]
y: [1, 3]
z: [2]

idx = -1 // index on source
cnt = 1
t = 0, indicies['x'] = [0, 4], first larger than idx is 0, update: idx = 0
t = 1, indicies['z'] = [2], first larger than idx is 2, update: idx = 2
t = 2, indicies['y'] = [1, 3], first larger than idx is 3, update: idx = 3
t = 3, indicies['x'] = [1, 3], first larger than idx is none! so you know you've
       exhausted source to find a subsequence. It's time to go back the start
       and find another match. So cnt = 2, (working on the second subsequence),
       and idx = 1 (first x appearance)
t = 4, indicies['z'] = [2], first larger than idx is 2, update: idx = 2
t = 5, indicies['z'] = [2], first larger than idx is none! Same logic, update
       idx = 2, making cnt = 3 as a new start
t = 6, indicies['x'] = [0, 4], first larger than idx is 4! update: idx = 4
*/
class Solution {
 public:
  int shortestWay(string source, string target) {
    std::unordered_map<char, std::vector<int>> charIndices;
    const int sSz = source.size();
    for (int i = 0; i < sSz; ++i) {
      charIndices[source[i]].push_back(i);
    }
    const int tSz = target.size();
    int curSourceIdx = -1;
    int res = 1;
    for (int t = 0; t < target.size(); ++t) {
      auto it = charIndices.find(target[t]);
      if (it == charIndices.end()) {
        return -1;
      }
      auto& indicies = it->second;
      auto it2 =
          std::upper_bound(indicies.begin(), indicies.end(), curSourceIdx);
      if (it2 == indicies.end()) {
        curSourceIdx = indicies.front();
        res++;
      } else {
        curSourceIdx = *it2;
      }
    }
    return res;
  }
};