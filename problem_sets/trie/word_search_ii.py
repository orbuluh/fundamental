"""
some key to be faster ...
- once you found the word, you can delete from trie
- could delete even further, I guess
- once all the word are found, no longer need to search
- still not ideal, didn't check details yet.
"""


class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.isWord = False


class Trie:
    def __init__(self):
        self.word_cnt = 0
        self.root = TrieNode()

    def insert(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isWord = True
        self.word_cnt += 1


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)

        m, n = len(board), len(board[0])
        res, seen = [], [False] * m * n

        def _idx(i: int, j: int):
            return i * n + j

        def _dfs(i: int, j: int, path: str, node: TrieNode):
            nonlocal board, m, n, res, seen
            if trie.word_cnt == 0 or board[i][j] not in node.children:
                return
            idx = _idx(i, j)
            if seen[idx]:
                return
            seen[idx] = True
            node = node.children[board[i][j]]
            if node.isWord:
                node.isWord = False
                trie.word_cnt -= 1
                res += [path]
            for di, dj in [[1, 0], [0, -1], [-1, 0], [0, 1]]:
                ni, nj = i + di, j + dj
                if ni < 0 or nj < 0 or ni >= m or nj >= n:
                    continue
                _dfs(ni, nj, path + board[ni][nj], node)
            seen[idx] = False

        for i in range(m):
            for j in range(n):
                _dfs(i, j, board[i][j], trie.root)
        return res
