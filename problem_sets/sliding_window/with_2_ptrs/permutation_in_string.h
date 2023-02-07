/*
Get a counter for s1.

We maintain a sliding window in s2, where window must contain only matches in
s1.

How?
- whatever in the window, it will consume counter in s1
- match only happens when all elements in counter has >= 0 value
- When counter has < 0 value, we shrink the window until the criteria of "all
  counter has >= 0 value" meet again. (This "until" while loop is the key. you
  can't just pop one elements or so, you are deliberately making sure the
  window just keep the invariant)

Because we maintain such criteria in each iteration, we actually only need to
check that "counter[cur char] >= 0", as "cur char" is the one that could have
invalidated the criteria in this iteration.

- You can imagine, when there is something that is not in s1 at all, it will
  basically keep shrinking till removing the latest char. And window is
  basically reset.
- s1 = abcd s2 = abceabcd ==> when hitting e, window shrink through setting
  l to the next of e, and then r keep going till we find the match

And because window always meet the criteria that its consumption of
counter maintain counter to have all >= 0 value, when window size is the same
as s1, we find the full match!
*/

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    std::vector<int> counter(26, 0);
    auto charCnt = [&](char c) -> int& { return counter[c - 'a']; };
    for (auto c : s1) {
      charCnt(c)++;
    }
    const int sz = s1.size();
    const int sz2 = s2.size();
    for (int l = 0, r = 0; r < sz2; ++r) {
      auto& curCharCnt = charCnt(s2[r]);
      curCharCnt--;
      while (curCharCnt < 0) {
        charCnt(s2[l++])++;
      }
      if (r - l + 1 == sz) {
        return true;
      }
    }
    return false;
  }
};