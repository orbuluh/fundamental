/*
The point to not get the TLE is likely how you maintain the path along the way.
Making the full path is likely to TLE.

So the idea is to keep the prevs array + a steps array.

steps[i] stores the level where word i should appear in shortest path.
         if word i is in a shortest path, it can only be at that level
prevs[i] stores the previous index that can make word i to be at that
         certain level

With this two mechanism, when you do bfs, you don't need to record each of
the current path. And this will in general much faster at the end.
*/
class Solution {
  public:
    std::vector<std::vector<int>> prevs;
    std::vector<int> steps;
    std::bitset<501> visited;
    std::unordered_map<std::string_view, int> wordIdx;
    int beginWordIdx = -1;
    int endWordIdx = -1;

    void initData(std::string_view beginWord, std::string_view endWord,
                  vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) {
                beginWordIdx = i;
            } else if (wordList[i] == endWord) {
                endWordIdx = i;
            }
            wordIdx[wordList[i]] = i;
        }

        if (beginWordIdx == -1) {
            beginWordIdx = wordList.size();
            wordList.emplace_back(beginWord);
            wordIdx[beginWord] = beginWordIdx;
        }
        visited.set(beginWordIdx);
        prevs = std::vector<std::vector<int>>(wordList.size());
        steps = std::vector<int>(wordList.size(), 0);
    }

    std::vector<int> getNext(std::string_view curW) {
        // this way will make it slightly faster than building the adjacent
        // graph in the beginning.
        std::string w{curW};
        std::vector<int> res;
        for (int i = 0; i < w.size(); ++i) {
            char oriChar = w[i];
            for (int j = 0; j < 26; ++j) {
                char newChar = 'a' + j;
                if (newChar == oriChar)
                    continue;
                w[i] = newChar;
                auto it = wordIdx.find(w);
                if (it == wordIdx.end())
                    continue;
                if (visited.test(it->second))
                    continue;
                res.push_back(it->second);
            }
            w[i] = oriChar;
        }
        return res;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        initData(beginWord, endWord, wordList);
        std::queue<int> bfs;
        bfs.push(beginWordIdx);
        int level = 0;
        bool foundEnd = false;
        while (!bfs.empty() && !foundEnd) {
            const int curSz = bfs.size();
            std::unordered_set<int> newVisit;
            for (int i = 0; i < curSz; ++i) {
                const int curIdx = bfs.front();
                bfs.pop();
                auto neighbors = getNext(wordList[curIdx]);
                for (int nextIdx : neighbors) {
                    if (steps[nextIdx]) {
                        // critical point 1 - if word i is in the index `level`
                        // of one shortest path, then it can only be at index
                        // `level` in other shortest path. Otherwise, it must
                        // not consist of a shortest path and we can skip
                        if (steps[nextIdx] == level + 1) {
                            prevs[nextIdx].push_back(curIdx);
                        }
                        continue;
                    }
                    steps[nextIdx] = level + 1;
                    prevs[nextIdx].push_back(curIdx);
                    bfs.push(nextIdx);
                    if (!foundEnd && nextIdx == endWordIdx)
                        foundEnd = true;
                    newVisit.insert(nextIdx);
                }
            }
            for (int v : newVisit) {
                visited.set(v);
            }
            level++;
        }
        if (!foundEnd)
            return {};
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> curPath;
        buildAns(res, curPath, wordList, endWordIdx);
        return res;
    }

    void buildAns(std::vector<std::vector<std::string>>& res,
                  std::vector<std::string>& curPath,
                  const vector<string>& wordList, int curIdx) {
        // we record the prev, so make path in a backward way
        if (curIdx == beginWordIdx) {
            res.push_back(curPath);
            res.back().push_back(wordList[curIdx]);
            std::reverse(res.back().begin(), res.back().end());
            return;
        }
        for (int preIdx : prevs[curIdx]) {
            curPath.push_back(wordList[curIdx]);
            buildAns(res, curPath, wordList, preIdx);
            curPath.pop_back();
        }
    }
};