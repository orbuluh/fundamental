class Solution {
  public:
    using WordCntDict = unordered_map<std::string_view, int>;
    WordCntDict wordIdxTemplate_;
    int wSz_ = 0;
    int wordsCnt_ = 0;
    vector<int> findSubstring(string s, vector<string>& words) {
        wSz_ = words.front().size();
        wordsCnt_ = words.size();
        for (int i = 0; i < words.size(); ++i) {
            wordIdxTemplate_[words[i]]++;
        }
        vector<int> res;
        // different starting point of mod won't overlap
        // consider case like s = "aaaaaa", words = ["a", "a"]
        // we basically search from index 0 and index 1 separately
        for (int i = 0; i < wSz_; ++i) {
            findFullMatch(s, i, words, res);
        }
        return res;
    }

    void findFullMatch(std::string_view s, int sIdx,
                       const vector<string>& words, std::vector<int>& res) {
        // Idea: sliding window for the full combo and adjust
        // say: s = "ababca", words = ["a", "b", "c"]
        //           012345
        // when at index 2, we basically pop index 0
        // when at index 3, we basically pop index 1
        // when at index 4, we found match
        // when at index 5, we basically pop index 2, still full match
        WordCntDict wordIdx = wordIdxTemplate_; // make a copy
        int wordLeft = wordsCnt_;
        int beginOfFullMatch = -1;
        while (sIdx < s.size()) {
            std::string_view w(&s[sIdx], wSz_);
            auto it = wordIdx.find(w);
            if (it == wordIdx.end()) {
                // word not valid, there is no full match combo, we have to
                // basically reset if you just copy again (e.g. wordIdx =
                // wordIdxTemplate_), it will be too slow
                while (wordLeft != wordsCnt_) {
                    auto curW = std::string_view(&s[beginOfFullMatch], wSz_);
                    beginOfFullMatch += wSz_;
                    wordIdx[curW] += 1;
                    wordLeft++;
                }
                beginOfFullMatch = -1;
                sIdx += wSz_;
                continue;
            }
            // if certain words exhaust, we have to pop the combo till we hit
            // the same word, only by then we know the current word forms a
            // combo and we do maintain previous other valid combo
            if (!wordIdx[w]) {
                bool found = false;
                while (!found) {
                    auto curW = std::string_view(&s[beginOfFullMatch], wSz_);
                    found = curW == w;
                    beginOfFullMatch += wSz_;
                    wordIdx[curW] += 1;
                    wordLeft++;
                }
            }
            wordIdx[w]--;
            wordLeft--;
            if (beginOfFullMatch == -1) {
                beginOfFullMatch = sIdx;
            }
            // e.g. the sliding window contains full words
            if (!wordLeft) {
                res.push_back(beginOfFullMatch);
            }
            sIdx += wSz_;
        }
    }
};