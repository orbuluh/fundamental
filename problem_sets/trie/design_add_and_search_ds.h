/*
fastest solution in OJ was using vector of unordered_set to record all words
for each of word length. And when query has '.', it basically search all words
in the whole unordered_set with that specific length.

Below leave the basic trie ways.

The most memory efficient implementation in OG was using pmr + shared pointer
*/

class WordDictionary {
  struct TrieNode {
    std::array<TrieNode*, 26> next = {};
    bool isWord = false;
  };
  TrieNode root_;

 public:
  WordDictionary() = default;

  void addWord(string word) {
    auto ptr = &root_;
    for (char c : word) {
      const int idx = c - 'a';
      if (!ptr->next[idx]) {
        ptr->next[idx] = new TrieNode();
      }
      ptr = ptr->next[idx];
    }
    ptr->isWord = true;
  }

  bool search(string word) { return dfs(word, 0, &root_); }

 private:
  bool dfs(std::string_view word, int wordIdx, TrieNode* node) {
    if (wordIdx >= word.size()) {
      return node->isWord;
    }
    if (word[wordIdx] != '.') {
      const int idx = word[wordIdx] - 'a';
      if (!node->next[idx]) {
        return false;
      }
      return dfs(word, wordIdx + 1, node->next[idx]);
    } else {
      for (auto ptr : node->next) {
        if (ptr && dfs(word, wordIdx + 1, ptr)) {
          return true;
        }
      }
    }
    return false;
  }
};
