class Solution {
  /*

  (A) means 2 * A
  say A = B + C
  (A) = (B+C) = 2*(B+C) = 2*B + 2*C = (B) + (C)

  ->e.g. it's like 2 * (1 + 1) = 2 * 1 + 2 * 1

  say B = (), C = ()
  (B C ) =  (B) + (C)
  (()()) = (()) + (())

  what does this imply?

  whenever we saw a (), it provide some score that we can extract, and the score
  it provides actually relates to its parentheses depth.

  Specifically, it provides score 2^(depth - 1)

  (()())
    ^  ....... the first () is at depth 2, it provides score 2^(2 - 1) = 2
      ^ ...... second() is at depth 2, also provides score 2
  the result is 2 + 2 = 4

  ((())())
     ^  ....... () at depth 3, it provides 2 ^ (3 - 1) = 4
        ^  .....() at depth 2, it provides 2 ^ (2 - 1) = 2
  the result is 4 + 2 = 6
  */
 public:
  int scoreOfParentheses(string s) {
    int depth = 0;
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        depth++;
      } else {
        depth--;
        if (s[i - 1] == '(') {
          result += (1 << depth);
        }
      }
    }
    return result;
  }
};