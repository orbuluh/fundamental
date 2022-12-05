/*
@lee215's solution ... the beautiful parts are:
1. doing replacement from the end will ensure all the parts afterwards are
   unchanged after handling.

2. because of 1, you can think for a replacement, it basically makes original
   string to 3 parts:
   (1) substring before replacement
   (2) affected portion that might be replaced
   (3) substring after the affected portion

For example:  a [b] c [d] e
Say you are going to replace [d] to [ggg] and [b] to [jjj]

you do it from the back and separate s to
    (1) abc
    (2) d  ---> replaced to ggg
    (3) e
so after first replacement, s becomes abcggge

Then handling the next portion:
    (1) a
    (2) b  ---> replaced with jjj
    (3) cggge

Such idea of "breaking original string to 3 parts" is actually the critical part
to make the code concise ... your own solution will have to keep track of what
is changed and what is not...


Your original implementation - use std::map to ensure you can traverse each part
in order. But you will have to book-keeping about where you at in the original
string. And fill it in when it's not affected by the replaced parts.

string findReplaceString(string s, vector<int>& indices,
                         vector<string>& sources, vector<string>& targets) {
  std::map<int, std::pair<int, std::string>> replacedCache;
  for (int i = 0; i < indices.size(); ++i) {
    const auto substr = s.substr(indices[i], sources[i].size());
    if (substr == sources[i]) {
      replacedCache[indices[i]] = std::make_pair(substr.size(), targets[i]);
    }
  }
  std::string replacedStr;
  auto shouldStartIdx = 0;
  for (const auto& [idx, szStrPair] : replacedCache) {
    const auto& [sz, str] = szStrPair;
    if (idx != shouldStartIdx) {
      replacedStr += s.substr(shouldStartIdx, idx - shouldStartIdx);
      shouldStartIdx = idx;
    }
    replacedStr += str;
    shouldStartIdx += sz;
  }
  replacedStr += s.substr(shouldStartIdx);
  return replacedStr;
}
*/


class Solution {
 public:
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    std::vector<std::pair<int, int>> orderedIndices;
    for (int i = 0; i < indices.size(); ++i) {
      orderedIndices.emplace_back(indices[i], i);
    }
    std::sort(orderedIndices.rbegin(), orderedIndices.rend());

    for (int i = 0; i < orderedIndices.size(); ++i) {
      const auto& [sIdx, inputIdx] = orderedIndices[i];
      int sz = sources[inputIdx].size();

      if (sIdx + sz > s.size()) continue;

      auto replacedStr = s.substr(sIdx, sz);
      if (replacedStr == sources[inputIdx]) {
        replacedStr = targets[inputIdx];
      }
      s = s.substr(0, sIdx) + replacedStr + s.substr(sIdx + sz);
    }
    return s;
  }
};