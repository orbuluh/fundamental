/*
Idea - we don't need to build counter for each word in words2 then
check if it's a subset of the counter of the word in words1.

Rather - since universal requires every word in word2 are subset of
word1's word - we can just build a filter based on words in word2.

filter[c] represents the maximum appearance of char c among the word
in words2

Then we build the counter for the word in words1. If in the end, the
counter of any char c for the word in word1 isn't larger than the
filter[c] - it means it can't cover at least one of the word in word2.
So it's not universal!
*/
class Solution {
    std::vector<int> wordCnt;

  public:
    void resetWordCnt(std::string_view word) {
        std::fill(wordCnt.begin(), wordCnt.end(), 0);
        for (char c : word) {
            wordCnt[c - 'a'] += 1;
        }
    }
    std::vector<std::string> wordSubsets(vector<string>& words1,
                                         vector<string>& words2) {
        wordCnt = std::vector<int>(26, 0);
        std::vector<int> filter(26, 0);
        for (int i = 0; i < words2.size(); ++i) {
            resetWordCnt(words2[i]);
            for (int j = 0; j < 26; ++j) {
                filter[j] = std::max(wordCnt[j], filter[j]);
            }
        }

        std::vector<std::string> res;
        for (int i = 0; i < words1.size(); ++i) {
            resetWordCnt(words1[i]);
            bool universal = true;
            for (int j = 0; universal && j < 26; ++j) {
                if (filter[j] > wordCnt[j]) {
                    universal = false;
                }
            }
            if (universal)
                res.emplace_back(std::move(words1[i]));
        }
        return res;
    }
};