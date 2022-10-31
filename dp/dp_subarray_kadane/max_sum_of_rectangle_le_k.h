/*

For a rectangle that is on a specific column - it's basically like a
max-subarray across different rows.

And for a rectangle across several column, it's basically like finding range sum
you add each column's value up, and when you checking a new column, it's again
like finding max-subarray across different rows again.

We basically need to check all possible [colL, colR] combination - then for each
specific range of [ColL, colR], we can scan the rows to find the max sum.

As using range sum query concept, say we find
rect(row_i, colL, colR) - rect(row_j, colL, colR) creates a larger value than
what we've seen, and the value is <= k, we know we find a better candidate.
And because we we check row_i, we want to find if such row_j exists, we can
basically put them into std::set and use lower_bound to find such value.

One optimization is that we can do Kadane before we going into the lower_bound
phase. As if we know that for [colL, colR], the rectangle's max subarray sum is
<= k already, we know we don't even need to apply lower_bound to find the rows.
We can just update the maximum value and continue to check next column
combination
*/
class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int maxSum = INT_MIN;
    for (int colL = 0; colL < n; ++colL) {
      std::vector<int> rowSumBetweenCols(m, 0);
      for (int colR = colL; colR < n; ++colR) {
        if (maxSum == k) return k;
        // optimization - calculate max sub array along the way
        // and if max sub array is already <= k, we don't need
        // to do the binary search later!
        int kadane = 0, maxKadane = INT_MIN;
        for (int i = 0; i < m; ++i) {
          rowSumBetweenCols[i] += matrix[i][colR];
          // e.g. if prev kadane is negative, it would have been ignored
          kadane =
              std::max(rowSumBetweenCols[i], rowSumBetweenCols[i] + kadane);
          maxKadane = std::max(maxKadane, kadane);
        }
        if (maxKadane <= k) {
          // optimization, exit early if max sub array sum <= k already
          maxSum = std::max(maxSum, maxKadane);
          continue;
        }

        // the maxKadane is more than k, we need to do binary search to find
        // the potential candidate
        std::set<int> seenSum({0});
        int curSum = 0;
        // Kadane's algorithm, again
        for (auto sum : rowSumBetweenCols) {
          curSum += sum;
          if (curSum <= k) maxSum = std::max(curSum, maxSum);
          // say x is some seen sum
          // we hope to find: curSum - x <= k (which means retangle of curSum -
          // x has sum <= k) e.g. finding x >= curSum - k, e.g. finding lower
          // bound from seen
          auto it = seenSum.lower_bound(curSum - k);
          if (it != seenSum.end()) {
            if (*it == curSum - k) return k;
            const auto subsum = curSum - *it;
            // *it >= curSum - k because lower bound
            // so subsum = curSum - *it <= k
            // as sumsum != k, subsum must < k
            // and subsum could be a candidate of the result
            maxSum = std::max(subsum, maxSum);
          }
          seenSum.insert(curSum);
        }
      }
    }
    return maxSum;
  }
};