/*
https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116664/schematic-explanation-of-two-equivalent-dp-recurrence-formula

A beautiful state transition DP problem ...

The thinking process is that we need to find unique ways of recording different
arrangement (just like when you do a backtracking, you are maintaining the
sequence of what you've built)

And how do we do that? One possible way is using the type of last piece to
identify a unique sequence.

But then the question is, what could be the type of last piece?


                 (H) (V) (U) (D)
It could only be  --, |,  U, DD
                      |  UU   D

So say T(n) is number of ways ending on idx n, then we can gather

T(n) = T(n - 2)  // and then put 2 * H to cover (n-1)-th and n-th col
     + T(n - 1)  // and then put 1 * V to cover n-th col
     + ... How to deal with last piece being U or D?

If last piece at n is U, then before the last piece, it must look like
      n
...OO U
...O UU
Let's just say it's T_u(n - 1) so that it ends with a U' in n-1 col
where U' is basically the  OO  in the graph
                           O

Same, if last piece at n is D, then before the last piece, it must look like
       n
...O  DD
...OO  D
Let's just say it's T_d(n - 1) so that it ends with a D' in n-1 col
where D' is the   O  in the graph
                  OO

As tromino's shape is different, we know sequence ending with a tromino must not
have overlap with T(*), we are good to not double counting.

So we have:

T(n) = T(n - 2) + T(n - 1) + T_u(n - 1) + T_d(n - 1)


But then how do we actually make the T_u(n) or T_d(n) into the recursion?

Consider T_u(n), meaning at n, it ends with a U', and at n - 2, it's a vertical
boarder, what's the possibility?
     n
..X OO   ==> this case is covered by T(n - 2)
  X O
or   n
  U OO  ==> this case is covered by T_d(n - 1)
 UU O

So    T_u(n) = T(n - 2) + T_d(n - 1)
Same, T_d(n) = T(n - 2) + T_u(n - 1)

We got our recurrence equation. What's the base case?

T(0) = 1, T_u(0) = T_d(0) = 0
T(1) = 1, T_u(1) = T_d(1) = 0

Then we can basically build our result accordingly.
Also, because we only depend on the state in n - 2, n - 1 to form n
we could further make the space to be O(1) through mod 3 on index

for example, when we process column i = 2, we are using 0 and 1 as
source, so result index is 2 % 3 = 2, source indices are 0 % 3 and 1 % 3

Then we we process column i = 3, we are using 3 % 3 == 0 as result.
And source indices are 2 % 3 = 2 and 1 % 3 = 1

Same when we process column i = 4, result idx at 4 % 3 = 1, source indices
are 3 % 3 = 0 and 2 % 3 = 2.

So just use mod 3 on i, i-1, i-2 will let us safely to find the input indices
and the index to store result in this iteration.


Note that the recurrence can further improve ... but the below implementation
just use above and seems to be TC/SC good enough. For the record

T(n) = T(n - 1) + T(n - 2) + T_u(n - 1) + T_d(n - 1)  ... (1)
and
       T_u(n) = T(n - 2) + T_d(n - 1)   ...(2)
       T_d(n) = T(n - 2) + T_u(n - 1)   ...(3)

Substitute (2), (3) using n - 1 as input into (1)

T(n) = T(n - 1) + T(n - 2)
     + T(n - 1 - 2) + T_d(n - 1 - 1)
     + T(n - 1 - 2) + T_u(n - 1 - 1)

    = T(n - 1) + T(n - 2) + T(n - 3) + T_d(n - 2) + T(n - 3) + T_u(n - 2)

       ... regrouping ...

    = T(n - 1) + T(n - 3)
      + [ T(n - 2) + T(n - 3) + T_d(n - 2) + T_u(n - 2) ]

      ... the [...] part equal to T(n - 1) !! (OS: dang...)

    = T(n - 1) + T(n - 3) + T(n - 1) = 2*T(n - 1) + T(n - 3)

So you can just use even less memory ... but this isn't obvious nor actually
reduce much memory ... so not going do it here.
*/
class Solution {
  static constexpr int modNum = 1'000'000'007;

 public:
  int numTilings(int n) {
    if (n <= 2) return n;
    std::array<int, 3> t{};
    std::array<int, 3> u{};
    std::array<int, 3> d{};
    t[0] = t[1] = 1;
    auto mod = [&](int x) { return x % modNum; };
    for (int idx = 2; idx <= n; ++idx) {
      int i = idx % 3;
      int i_1 = (idx - 1) % 3;
      int i_2 = (idx - 2) % 3;
      u[i] = mod(t[i_2] + d[i_1]);
      d[i] = mod(t[i_2] + u[i_1]);
      t[i] = mod(mod(t[i_1] + t[i_2]) + mod(u[i_1] + d[i_1]));
    }
    return t[n % 3];
  }
};