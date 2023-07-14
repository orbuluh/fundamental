/*
Use len[n] to record the length of arithmetic series ending with n.
Process element from left to right, update with
len[n] = 1 + len[n - difference]

if len[n - difference] got updated with a larger value, then only
a new n happens to the updated n - difference can make
len[n] be updated with the larger value accordingly.

So along the way, we can simply keep the latest len[n] for any n,
which will record the length of latest AS that is ending with n.

And we simply update the max value we've seen along the way, so
we won't lose track on anything!
*/

class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    std::unordered_map<int, int> len;
    int res = 0;
    for (auto n : arr) {
      res = std::max(res, len[n] = len[n - difference] + 1);
    }
    return res;
  }
};