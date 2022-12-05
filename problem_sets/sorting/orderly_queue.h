/*
The idea is that when k > 1, it can be proofed that you can always swap adjacent
chars. And as long as you can swap adjacent chars, you can do a bubble sort. So
when k > 1, it's basically like sorting the input.

https://leetcode.com/problems/orderly-queue/discuss/165915/When-k-greater-1-you-can-reorder-any-way-you-like-Proof

Use k = 2 as example:

abc[XY]def: original string, say we want to swap XY
[XY]defabc: move a to the end, b to the end, c to the end, etc.
defabc[YX]: move Y to the end, we can do it because k > 1, then move X to the
            end.
abc[YX]def: move d to the end, e to the end, f to the end, etc.

And when k is only 1 ... the best we can do is rotate the sting character by
character and find the lexicographically minimal one. (O(n^2))
*/

class Solution {
 public:
  string orderlyQueue(string s, int k) {
    if (k > 1) {
      std::sort(s.begin(), s.end());
      return s;
    }
    std::string res = s;
    for (int i = 0; i < s.size() - 1; ++i) {
      s = s.substr(1) + s[0];
      res = std::min(res, s);
    }
    return res;
  }
};