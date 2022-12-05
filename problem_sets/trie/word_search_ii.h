class Solution {
 public:
  struct TrieNode {
    int wordIdx = -1;
    std::array<TrieNode*, 26> children = {};
  };

  void buildTrie(std::string_view w, int idx) {
    auto cur = &trie;
    for (char c : w) {
      TrieNode* nxt = cur->children[c - 'a'];
      if (!nxt) {
        cur->children[c - 'a'] = nxt = new TrieNode{};
      }
      cur = nxt;
    }
    cur->wordIdx = idx;
  }

  int idx(int r, int c) { return 12 * r + c; }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < words.size(); ++i) {
      buildTrie(words[i], i);
    }
    std::vector<std::string> foundW;
    std::bitset<144> seen;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(board, words, i, j, seen, foundW, &trie);
      }
    }
    return foundW;
  }

  void dfs(const vector<vector<char>>& board, const vector<string>& words,
           int i, int j, std::bitset<144>& seen,
           std::vector<std::string>& foundWord, TrieNode* trieNode) {
    // in the first call of dfs, trieNode is the root
    // so in this implementation, it's when you enter the dfs do you
    // point the trieNode pointer to the node representing the char
    int charIdx = board[i][j] - 'a';
    if (!trieNode->children[charIdx]) return;

    trieNode = trieNode->children[charIdx];
    if (trieNode->wordIdx != -1) {
      foundWord.emplace_back(words[trieNode->wordIdx]);
      // reset the wordIdx as we don't want to double output
      trieNode->wordIdx = -1;
    }

    int boardIdx = idx(i, j);
    seen.set(boardIdx);
    for (int d = 0; d < 4; ++d) {
      int ni = i + dir[d];
      int nj = j + dir[d + 1];
      if (ni < 0 || nj < 0 || ni >= board.size() || nj >= board[0].size() ||
          seen.test(idx(ni, nj))) {
        continue;
      }
      dfs(board, words, ni, nj, seen, foundWord, trieNode);
    }
    seen.reset(boardIdx);
  }

  TrieNode trie;
  std::array<int, 5> dir = {1, 0, -1, 0, 1};
};