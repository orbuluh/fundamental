class Solution {
  // if always insert reversely into trie
  // abcd insert dcba
  // when query, just follow the trie to confirm if it is

  // Situation
  // (1) palindrome break in different len
  //     a. short + long
  //     b. long + short
  // (2) palindrome breaks in same len

  // [1.a] ab / cdcba, reversely insert ba, abcdc
  // query ab: match with ab in abcdc and remaining cdc in trie is palindrome,
  // so it's good

  // [1.b] abcdc / ba, insert cdcba, ab
  // -> query abcdc: match ab and remaining cdc in query is palindrome
  // so it's good

  // [2] abc/cba insert cba, abc
  // check abc, seeing abc in trie, good
  // check cba, seeing cab in trie, good

  // so from [1. a] - when we build trie, we would like to see if the remaining
  // substring of a reversed string is palindrome. And because it's just a
  // substring of certain word, it has to be a list as several words could have
  // same substring that is a palindrome

  // from [1.b] - when we query, we actually have to break the query string down

  // One thing need to think through is where to put the list of palindrome
  // suffix. Taking further look on [1.a] - query string is ab, and you match
  // trie's ab, and then the loop ends because query string exhaust. So your
  // pointer will be on the node of value b.

  // The complexity: say the average word len is k. When you insert and query,
  // for each workd, you are checking whether substring is a palindrome or not.
  // So both of them will be O(k^2) operation for one word, and there is n words
  // so the complexity os O(n * k^2)!

 public:
  struct TrieNode {
    TrieNode() : children(26, nullptr) {}
    bool isMatch(int idx) { return wordIdx >= 0 && wordIdx != idx; }
    int wordIdx = -1;  // wordIdx < 0 indicates no word ending here
    std::vector<int> idxesOfSuffixIsPalin;
    std::vector<TrieNode*> children;
  };

  TrieNode root;

  void insertWord(std::string_view w, int wordIdx) {
    auto triePtr = &root;
    if (w.empty()) triePtr->wordIdx = wordIdx;
    for (int i = w.size() - 1; i >= 0; --i) {
      if (isPalindrome(w, 0, i)) {
        // inclusive with i - why? it only used when w[i] isn't in trie
        // and you are checking whether from i to end, it's a palindrome
        // already
        triePtr->idxesOfSuffixIsPalin.push_back(wordIdx);
      }
      char c = w[i];
      if (!triePtr->children[c - 'a']) {
        triePtr->children[c - 'a'] = new TrieNode();
      }
      triePtr = triePtr->children[c - 'a'];
    }
    triePtr->idxesOfSuffixIsPalin.push_back(wordIdx);
    triePtr->wordIdx = wordIdx;
  }

  bool isPalindrome(std::string_view w, int i, int j) {
    while (i < j) {
      if (w[i++] != w[j--]) return false;
    }
    return true;
  }

  std::vector<std::vector<int>> findMatch(std::string_view w, int idx) {
    std::vector<std::vector<int>> res;
    auto triePtr = &root;
    for (int i = 0; i < w.size(); ++i) {
      // for case [1.b], query string is longer, and we only need to match the
      // prefix of query string - and if remaining of query string is palindrome
      // , we find a match!
      if (triePtr->isMatch(idx) && isPalindrome(w, i, w.size() - 1)) {
        res.emplace_back(std::vector<int>{idx, triePtr->wordIdx});
      }
      if (!triePtr->children[w[i] - 'a']) {
        return res;
      }
      triePtr = triePtr->children[w[i] - 'a'];
    }

    // for case [1.a] when we matched ab with ba, check whether remaining is
    // palindrome in trie. If it is, it's a match for 1.a
    for (auto pIdx : triePtr->idxesOfSuffixIsPalin) {
      if (pIdx == idx) continue;
      res.emplace_back(std::vector<int>{idx, pIdx});
    }
    return res;
  }

  vector<vector<int>> palindromePairs(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      insertWord(words[i], i);
    }
    std::vector<std::vector<int>> res;
    for (int i = 0; i < words.size(); ++i) {
      auto match = findMatch(words[i], i);
      res.insert(res.end(), match.begin(), match.end());
    }
    return res;
  }
};