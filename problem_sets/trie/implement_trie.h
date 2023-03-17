class Trie {
 public:
  Trie() = default;

  void insert(string word) {
    auto ptr = findTrieNode(word, true);
    ptr->isWord = true;
  }

  bool search(string word) {
    auto node = findTrieNode(word);
    return node != nullptr && node->isWord;
  }

  bool startsWith(string prefix) { return findTrieNode(prefix); }

 private:
  struct TrieNode {
    bool isWord = false;
    std::array<TrieNode*, 26> next = {};
  };
  TrieNode tree;
  static constexpr int preSz = 1000;
  std::array<TrieNode, preSz> preAlloc;
  int preAllocIdx = 0;

 private:
  TrieNode* genNewNode() {
    if (preAllocIdx < preSz) {
      return &preAlloc[preAllocIdx++];
    } else {
      return new TrieNode();
    }
  }

  TrieNode* findTrieNode(std::string_view prefix, bool insert = false) {
    auto ptr = &tree;
    for (char c : prefix) {
      const auto idx = c - 'a';
      if (!ptr->next[idx]) {
        if (!insert) {
          return nullptr;
        } else {
          ptr->next[idx] = genNewNode();
        }
      }
      ptr = ptr->next[idx];
    }
    return ptr;
  }
};