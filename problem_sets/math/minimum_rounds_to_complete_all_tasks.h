/*
From @lee215

you can see that if a freq can be composed by 3*x + 2*y = f, with the maximum
x, then we can solve it.

Originally you use a dp memorize + back tracking to solve, but @lee215 provide
the math solution...

Basically f can only be either the below case:

f == 1: -1
f == 2: 1
f == 3: 1
f == 3n: n

Then :bulb::bulb:

f == 3n + 1, then f == 3(n - 1) + 4 == 3*(n - 1) + 2 * 2
             e.g. return n - 1 + 2 = n + 1
f == 3n + 2 == 3n + 2 * 1, e.g. return n + 1

There can't be other case mathematically, so you are good to go.

And you can actually even consolidate the logic ...

f == 1: -1
else return std::ceil(f/3)!!

--> e.g. if f == 2, 3, f/3 == 0.xxxx, return 1
--> if f == 3n, return f/3
--> else return int(f/3) + 1

(caveat: need to / 3.0 not / 3)!

*/
class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    std::unordered_map<int, int> counter;
    for (auto t : tasks) {
      counter[t] += 1;
    }
    int allCnt = 0;
    for (const auto& [t, f] : counter) {
      if (f == 1) return -1;
      allCnt += std::ceil(f / 3.0);
    }
    return allCnt;
  }
};