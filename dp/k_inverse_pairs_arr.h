class Solution {
    /*
    for arr with size n
    - if n is at arr[-1], inversion must comes from 1 -> n - 1
    - if n is at arr[-2], 1 inversion must exist, e.g. n = 3, [1, 3, 2]
    - if n is at arr[-3], 2 inversion must exist, e.g. n = 3, [3, 1, 2], [3, 2, 1]
    ...
    - if n is at arr[n - x], x - 1 inversion include n must exist

    From: https://leetcode.com/problems/k-inverse-pairs-array/discuss/104815/Java-DP-O(nk)-solution

    dp[n][k] denotes the number of arr that have
    - k inverse pairs
    - for arr composed of 1 to n

    - we can establish the recursive relationship between dp[n][k] and dp[n-1][i] where i < k:

    dp[n][k] =
        dp[n-1][k]   // put n at last position, all k inverse should come from first n-1 numbers
      + dp[n-1][k-1] // put n at last 2nd, 1 pairs including n, rest k - 1 pairs from [1 ... n-1]
      + dp[n-1][k-2] // put n at last 3rd, 2 pairs including n, rest k - 2 pairs from [1 ... n-2]
      + ...
      + dp[n-1][1]   // put n at last kth, all k - 1 pairs including n, rest 1 pair from [1 ... n-1]
      + ...
      + dp[n-1][k-(n-1)] // for k' <= 0, dp[n][k'] = 0 basically

    The more magic part:

    (1) dp[n][k-1] =             dp[n-1][k-1] + dp[n-1][k-2] + ... + dp[n-1][k-n+1] + dp[n-1][k-1-n+1]
    (2) dp[n][k] =  dp[n-1][k] + dp[n-1][k-1] + dp[n-1][k-2] + ... + dp[n-1][k-n+1]

    (2) - (1) we get -> dp[n][k] - dp[n][k-1] = dp[n-1][k] - dp[n-1][k-1-n+1]
    e.g. final recursion:
        dp[n][k] = dp[n][k-1] + dp[n-1][k] - dp[n-1][k-n]

    base case:
    - when k == 0, dp[:][0] = 1, e.g. 1 way of non reversing
    ...

    The other direction of thinking this:

    https://leetcode.com/problems/k-inverse-pairs-array/discuss/104822/Python-Straightforward-with-Explanation

    Suppose we know dp[n][k], the number of permutations of (1...n) with k inverse pairs.

    Looking at a potential recursion for dp[n+1][k],
    depending on where we put the element (n+1) in our permutation,
    we may add 0, 1, 2, ..., n new inverse pairs.

    For example, if we have any permutation consist of [1...4], representing as x x x x
    inserting a 5 into the permutation ... because 5 > any of [1...4]

    5 x x x x creates 4 new inverse pairs
    x 5 x x x creates 3 new inverse pairs
    ...
    x x x x 5 creates 0 new inverse pairs

    Thus, dp[n+1][k] = sum_{x=0..n} dp[n][k-x].
    */
public:
    static constexpr int mod = 1'000'000'007;
    int kInversePairs(int maxN, int tgtRev) {
        std::vector<std::vector<long>> dp(maxN + 1, std::vector<long>(tgtRev + 1, 0));
        const long maxRevOfMaxN = maxN * (maxN - 1) / 2;
        if (tgtRev > maxRevOfMaxN) return 0;
        if (tgtRev == 0 || tgtRev == maxRevOfMaxN) return 1;
        for (long n = 1; n <= maxN; ++n) {
            // e.g. n number had at most n - 1 reversed, so k must < n
            dp[n][0] = 1; // only 1 way of non reverse
            const long maxRevOfN = n * (n - 1) / 2;
            const long maxRev = std::min(static_cast<long>(tgtRev), maxRevOfN);
            for (long k = 1; k <= maxRev; ++k) {
                dp[n][k] = (dp[n][k-1] + dp[n-1][k]);
                if (k >= n)
                    dp[n][k] -= dp[n-1][k-n]; // because mod, dp[n][k] could become negative
                dp[n][k] = (dp[n][k] + mod) % mod; // +mod here negate the case dp[n][k] become negative
            }
        }
        return dp[maxN][tgtRev] % mod;
    }
};