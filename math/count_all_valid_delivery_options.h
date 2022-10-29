/*
P1 ... Pn
D1 ... Dn

number of permutation s.t. Pi < Di

backtracking?

make a vector of 2n size, in each dfs, just try to fill in Pi and Di accordingly
(fill pi then iterate all other open pos?)

Is there a mathmatical solution?

Denote P1, P2, P3 as A, B, C
   and D1, D2, D3 as a, b, c

We can arrange A, B, C first, where there are 3! permutations

Without loss of generality, that's consider the case A B C
and now let's see how to insert a, b, c:

A_B_C_

We can see that c has only 1 place to go as C is the last one
b has 2 places to go at this point
a has 3 places to go at this point

So let's go with the determined one: setting c: ABCc

A_B_C_c_

You can see now b has 2 + 1 place to insert now (2 is before c was inserted)
And a has 3 + 1 places to insert now (3 was before c was inserted)

Without loss of generality, let's try b first and consider the
case: ABCbc:

A_B_C_b_c_

now we have (3 + 1) + 1 places to insert a (3 + 1 was before b was inserted)

So we can find the pattern for n delivery and pickup ...

There are n! ways to permute delivery time D1 to Dn

Then for inserting the pickup time....

For last delivery time's pick up, there are ony 1

the 2nd last: there are 2 + 1 ways to insert

the 3nd last: there are 3 + 1 + 1 ways to insert

...

the n-th last: there are n + (n - 1) ways to insert

So overall, it will be

n! * 1 * (2 + 2 - 1) * (3 + 3 - 1) * ... (n + n - 1)
*/
class Solution {
 public:
  static constexpr int mod = 1'000'000'007;
  int countOrders(int n) {
    long res = 1;
    for (int i = 1; i <= n; ++i) {
      res *= (i % mod);
      res %= mod;
      res *= (2 * i - 1);
      res %= mod;
    }
    return res;
  }
};