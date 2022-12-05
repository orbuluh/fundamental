/*
Idea: using the template of counting substring ...

keep a valid window of finding an anagram, output it and invalidate it
then finding next one, using 2 pointers.

The caveat here is that you need to maintain the window size as anagram is with
the same size. So overall it might be easier to do a standard sliding window
where you maintain a counter of p, and a counter of sliding window. And just
compare if 2 counters are the same while you iterate...
*/
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int l = 0;
    int r = 0;
    int unmatch = p.size();
    auto idx = [](char c) { return c - 'a'; };
    std::vector<int> counter(26, 0);
    for (char c : p) {
      counter[idx(c)]++;
    }
    std::vector<int> res;
    while (r < s.size()) {
      // r will become non-inclusive
      if (counter[idx(s[r++])]-- > 0) {
        unmatch--;
      }
      while (l < r && counter[idx(s[l])] < 0) {
        counter[idx(s[l++])]++;  // remove unrelated chars
      }
      while (r - l > p.size()) {
        // shrink l s.t. the window size is right
        // along the way it could invalid the window again
        // consider: s = aabc, p = abc
        // it would have become, l = 0, r = 4, unmatched = 0
        // you need to make l = 1, so that r - l is as p.size()
        if (++counter[idx(s[l++])] > 0) {
          unmatch++;
        }
      }
      if (unmatch == 0) {
        res.push_back(l);
        counter[idx(s[l++])]++;  // make it invalid again
        unmatch++;
      }
    }
    return res;
  }
};