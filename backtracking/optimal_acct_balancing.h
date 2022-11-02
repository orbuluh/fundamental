/*

Example 1:

idx  0    1   2
    -10  10
     5        -5
----------------
    -5   10  -5

--------------------

idx 0    1    2
    -10  10
    1    -1
         -5   5
    5        -5
--------------------
    -4   4    0


So it will be an array of positive and negative value, call such array, with
0 value removed, as the balance array.

Question ... will min txn be consecutively apply

min debt + max credit, till debt are all 0?

No .. consider

idx 0    1    2   3   4
    -4        4
         -4   4
                 -5   5
--------------------
    -4   -4   8  -5   5   --> balance array

-5 -4 -4 5 8
-4 -4 3 5  ...txn=1  (-5 + 8)
-4 1 3 ... txn=2  (-4 + 5)
-1 1 ... txn=3 (-4 + 3)
...txn = 4 (-1 + 1)

On the other hand if you match -5, 5, then -4 and -4 with 8, txn only needs 3

So it's like if any of the subarray sum of negative value equal to a positive
value, rather, we should try to group them in a way to minimize the transaction.

so a group should be a subarray with sum 0? This is actually correct. But doing
this (in a DP way is much more difficult...)

(Note: people identify this problem can be reduced to NP-hard 3 partition
problem... so even DP, the problem is still a NP-hard problem.)

Here put the non-DP, DFS backtracking, which is a brute force solution first.

The idea is to make sure while you dfs, the state is unique. And a state is
through assuming debt before an index has been settled.

*/
class Solution {
 public:
  std::vector<int> balance;

  int minTransfers(vector<vector<int>>& transactions) {
    initBalance(transactions);
    return settleAfterIdx(0);
  }

  int settleAfterIdx(int idx) {
    // dfs ... invariant, it's all settled before idx
    while (idx < balance.size() && balance[idx] == 0) {
      idx++;
    }
    if (idx == balance.size()) {
      return 0;
    }

    int minTxn = INT_MAX;
    long toSettle = balance[idx];
    for (int i = idx + 1; i < balance.size(); ++i) {
      if (toSettle * balance[i] >= 0) {
        continue;
      }
      // use later to clean up idx, dfs into idx + 1
      // (so before idx, it's all settled)
      balance[i] += toSettle;
      minTxn = std::min(minTxn, settleAfterIdx(idx + 1) + 1);
      balance[i] -= toSettle;
    }
    return minTxn;
  }

  void initBalance(vector<vector<int>>& transactions) {
    balance = std::vector<int>(12, 0); // 12 because problem constraint
    for (const auto& txn : transactions) {
      balance[txn[0]] -= txn[2];
      balance[txn[1]] += txn[2];
    }
    balance.erase(std::remove_if(balance.begin(), balance.end(),
                                 [](int val) { return val == 0; }),
                  balance.end());
  }
};