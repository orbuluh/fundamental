
/*
assuming dp[i][j] is the minimum operations to make s1[i:] match s2[j:]
base case:
    if s1[i:] and s2[j:] are both empty, operation is 0
    if only s1[i:] is empty
        -> minimum step is basically all insert to s1 to match s2
        -> dp[i][j] = s2.size() - j
    if only s2[j:] is empty
        -> minimum step is basically all remove from s1 to match s2
        -> dp[i][j] = s2.size() - j
recursion:
    if s1[i] == s2[j], it's a match, no operation needed
        - e.g. s1 = ab, s2 = ad -> editDistance(ab, ad) == editDistance(b, d)
        - e.g. dp[i][j] = dp[i-1][j-1]

    otherwise construct depends on the operations ...
    Question, how operation would do given it creates a optimal solution
    for the subproblems?

    [INSERT]
    say we use insert, we must insert s2[j] into s1[i]
    (insert other stuff would not have made this optimal solution.)
    say i is 0, j is 0 below, s1[i] == b, s2[j] == d
    s1: b   -->  db
    s2: db       db
    e.g. thorough insert, we've matched s2[j], but as we insert,
         s1[i] isn't really processed yet, so it's like
         editDistance(b, db) == editDistance(d, '') + 1
    e.g. dp[i][j] = dp[i][j+1] + 1

    [DELETE]
    say we use delete, we must delete s1[i] while no change in s2
    s1: bd   -->   d
    s2: d    -->   d
    e.g. editDistance(bd, d) == editDistance(d, d) + 1
    e.g. dp[i][j] = dp[i+1][j] + 1

    [Replace]
    say we use replace, we must have replaced s1[i] to be equal to s2[j]
    s1: bd   -->   ad
    s2: ad   -->   ad
    e.g. editDistance(bd, ad) == editDistance(d, d) + 1
    dp[i][j] = dp[i+1][j+1] + 1


    [The recursion]
    As we want to find the minimal operation, we are looking the best
    operation:
    dp[i][j] = min(dp[i+1][j], dp[j+1][i], dp[i+1, j+1]) + 1

*/
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int s1Sz = word1.size();
    const int s2Sz = word2.size();
    std::vector<std::vector<int>> dp(s1Sz + 1, std::vector<int>(s2Sz + 1, 0));

    // matching empty w1 with w2 should basically take the number of insertion
    for (int j = s2Sz - 1; j >= 0; --j) {
      dp[s1Sz][j] = s2Sz - j;
    }
    // matching w1 with empty w2 should basically take the number of deletion
    for (int i = s1Sz - 1; i >= 0; --i) {
      dp[i][s2Sz] = s1Sz - i;
    }
    // build up the recurrence
    for (int i = s1Sz - 1; i >= 0; --i) {
      for (int j = s2Sz - 1; j >= 0; --j) {
        if (word1[i] == word2[j]) {
          dp[i][j] = dp[i + 1][j + 1];
        } else {
          int insertOps = dp[i][j + 1];
          int deleteOps = dp[i + 1][j];
          int replaceOps = dp[i + 1][j + 1];
          dp[i][j] = 1 + std::min(insertOps, std::min(deleteOps, replaceOps));
        }
      }
    }
    return dp[0][0];
  }
};