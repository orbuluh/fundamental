/*
Following along the thought process in the backtracking/optimal_acct_balancing.h

We create the balance array from input vector, and through example:

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

We guess that to get a minimum transaction, we need to try to partition the
balance array in a way that for each partition, it sums to 0.

There is a nice solution having good explanation here:
https://leetcode.com/problems/optimal-account-balancing/discuss/2128379/O(n2n-%2B-3n)%3A-Dynamic-programming-%2B-submasks
https://leetcode.com/problems/optimal-account-balancing/discuss/219187/Short-O(N-*-2N)-DP-solution-with-detailed-explanation-and-complexity-analysis
https://leetcode.com/problems/optimal-account-balancing/discuss/954374/Proof-of-correctness-of-the-very-short-DP-solution

Let me put my interpretation here as well...

1. Since the sum of balance array is 0, we are guaranteed there is at least one
   way to partition where we take the full array in one set.

2. Supposed we are able partition a set with x values in the set. We are sure
   that through x - 1 transactions, we can settle for everyone. Why? say a
   transaction is like an edge between 2 values in set, and each value in set
   is like a node. Then the set should be a graph. And such graph should have
   at least x - 1 edges to ensure the whole graph is connected. Or put it
   another way, we can transfer largest balance to second large, then transfer
   second largest to third, ...etc. To the end we transfer all balance from
   second smallest to the smallest, and the smallest will now have 0 balance.
   This operation takes x - 1 transactions.

3. Therefore, supposed original full set has n elements, and we can divide the
   it to m subset, each with sum 0, then we will have transaction n - m in total

      txn(s1) + txn(s2) + ... txn(sm)
   = (|s1| - 1) + (|s2| - 1) + ... + (|sm| - 1)
   = (|s1| + |s2| + ... + |sm|) - m
   = n - m   (sum of size of all subset is equal to the full subset n)


4. As the total transaction is n - m, we will want to maximize m, e.g. number of
   subset that can form a subset with zero sum. E.g. we want to find the minimal
   subset that sums to 0.

   Note: to find out the way to do such partition is actually a NP hard problem.
   (3-partition-problem, as some other thread mentioned. Didn't go into detail.)

5. The DP intuition for finding such subset:

  subset can be represented by bitmask, where the bitmask has n bits. If the bit
  is set, the corresponding bit index means the corresponding value is in the
  subset.

  say n is just 7, full set is represented as 1111111

  and supposed subset 1100110 has a sum of 0, then the complimentary subset
  0011001 must also has a sum of 0. (Because full set has a sum of 0) And
  because 2 subsets are complementary, they must be disjoined. So this gives us
  a way to break down the subproblem:

  Solution(1111111) = Solution(1100110) + Solution(0011001)

  And maybe Solution(1100110) can be further break down
           = Solution(0000110) + Solution(1100000)

  ^^ Note that when you break down a bitmask, you would only try to unset one of
  its setbit. Doing so would make sure you are only breaking down the current
  group to a smaller groups while not affecting the result of its complementary.

  E.g. subproblem 0000110 and 1100000 isn't related to original complement
  0011001 at all. So overall it was like:

  Solution(1111111) = Solution(1100110)                     + Solution(0011001)
                    = Solution(0000110) + Solution(1100000) + Solution(0011001)
                    = ... (if it can further break...)

*/
class Solution {
 public:
  std::vector<int> balance;

  int minTransfers(vector<vector<int>>& transactions) {
    initBalance(transactions);  // same as backtracking sol
    return partitionZeroSumGroup();
  }

  int partitionZeroSumGroup() {
    int n = balance.size();  // full set size
    int totalCombination = 1 << n;
    // full set bitmask is basically totalCombination - 1 in binary
    // which equal to 1....1 with size n

    std::vector<int> sum(totalCombination, 0);

    for (int bitmask = 1; bitmask < totalCombination; ++bitmask) {
      for (int j = 0; j < n; j++) {  // bitmask is n bits
        if (((bitmask >> j) & 1) == 0) {
          continue;
        }
        // since we know bitmask & (1 << j) is true
        // e.g. the j-th bit is 1. Doing i ^ (1 << j)
        // basically unset only the j-th bit.
        int bitmaskWithOneBitDiff = bitmask ^ (1 << j);
        sum[bitmask] = balance[j] + sum[bitmaskWithOneBitDiff];
      }
    }

    std::vector<int> maxPartitionSz(totalCombination, 0);

    for (int bitmask = 1; bitmask < totalCombination; ++bitmask) {
      if (sum[bitmask]) {
        continue;  // not a 0 sum subgroup, not even valid.
      }
      // the set represented by bitmask as one group have size 1
      // and we try to break it down later to see if we can partition further
      // to make it having a larger full partition size
      maxPartitionSz[bitmask] = 1;

      int subsetMask = bitmask;
      while (subsetMask) {
        if (sum[subsetMask] == 0) {
          int comMask = bitmask ^ subsetMask;
          maxPartitionSz[bitmask] =
              // if set can be divided to smaller subset, then we try to see if
              // it yields a bigger total partition size through partitioning.
              // (It might not as the subset might not have a 0 sum, which makes
              // maxPartitionSz[subsetMask] and  maxPartitionSz[comMask] both 0
              // and therefore smaller than the 1, which is the size when we
              // consider everything as a big group)
              std::max(maxPartitionSz[bitmask],
                       maxPartitionSz[subsetMask] + maxPartitionSz[comMask]);
        }
        subsetMask = (subsetMask - 1) & bitmask;
        // nothing fancy than it seems. Say bitmask = 1111
        // subsetMask | comMask looks like below in the loop here
        // 1111          0000
        // 1110          0001
        // 1101          0010
        // ...
        // 0010          1101
        // 0001          1110
        // ------------------
        // if bitmask = 1100
        // subsetMask | comMask looks like below in the loop here
        // 1100          0000
        // 1000          0100
        // 0100          1000
        // overall the magic that make you break the current bitset to subsets
      }
    }

    return n - maxPartitionSz[totalCombination - 1];
  }

  void initBalance(vector<vector<int>>& transactions) {
    balance = std::vector<int>(12, 0);  // 12 because problem constraint
    for (const auto& txn : transactions) {
      balance[txn[0]] -= txn[2];
      balance[txn[1]] += txn[2];
    }
    balance.erase(std::remove_if(balance.begin(), balance.end(),
                                 [](int val) { return val == 0; }),
                  balance.end());
  }
};