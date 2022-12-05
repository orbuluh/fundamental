/*
Consider the case of [1, 2, 3, 4]

when you've seen [1, 2, 3], then the 4, it would just better to keep appending
[1, 2, 3]. Why? [1, 2, 3, 4] is good but  [1, 2, 3], [4] is not.

Same for [1, 2, 3, 4, 5].
And when it's [1, 2, 3, 4, 5, 6] - whether it's
[1, 2, 3, 4, 5, 6] or [1, 2, 3], [4, 5, 6]
- it doesn't matter, both are valid.

So we can greedily try to append number to an already valid sequence.

so the idea is that say we always try to append the sequence to an already
legit sequence (e.g. the existing sequence need to be len >= 3 already.)
Then only when we really can't append the number to the existing seq, do we try
to create a new sequence. And the new sequence must be created in a way that
it's already a combo of 3 elements
*/

class Solution {
  public:
    bool isPossible(vector<int>& nums) {
        std::unordered_map<int, int> valCnt;
        std::unordered_map<int, int> tailCnt;
        for (auto n : nums)
            valCnt[n]++;
        for (auto n : nums) {
            if (valCnt[n] == 0) {
                // could have been used when create new valid seq
                continue;
            }
            valCnt[n]--;
            if (tailCnt[n - 1]) {
                // try to append to existing seq
                tailCnt[n - 1]--;
                tailCnt[n]++;
            } else if (valCnt[n + 1] > 0 && valCnt[n + 2] > 0) {
                // try to create new valid seq
                valCnt[n + 1]--;
                valCnt[n + 2]--;
                tailCnt[n + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};