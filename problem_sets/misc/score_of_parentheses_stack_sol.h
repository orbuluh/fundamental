class Solution {
  /*

  (()())()

  keep a stack
  when hitting ), we try to pop.
  if top is (, it means we can form a 1
  so we pop the (, and insert the 1
  if top is not ( but a number, we pop and add all the
  numbers out till we hit an non-number, and then we pop the ( out
  and push the 2*sum in
  at the end, we add all the numbers in the stack

  ( -> ((  -> (1 -> (1( -> (1 1 -> 4 -> 4( -> 4 1 -> 4 5

  */
 public:
  static constexpr int open = INT_MAX;
  int scoreOfParentheses(string s) {
    std::deque<int> vals;
    for (char c : s) {
      if (c == '(') {
        vals.push_back(open);
        continue;
      }
      if (vals.back() == open) {
        vals.pop_back();
        vals.push_back(1);
      } else {
        int sum = 0;
        while (vals.back() != open) {
          sum += vals.back();
          vals.pop_back();
        }
        vals.pop_back();
        vals.push_back(2 * sum);
      }
    }
    return std::accumulate(vals.begin(), vals.end(), 0);
  }
};