/*
You original solution with monotonic decreasing stack takes O(n) time and space.
Speed distribution wise not too bad, but some better solution in the discussion.

The idea is

1. if temp[i + 1] > temp[i], then ans[i] must be 1.
2. else, use the fact that ans[j] stores how far of idx
   can you see the first temperature higher than temp[j]:

   So if temp[i + 1] < temp[i], you can utilize ans vector
   to do a jump table and find the first idx in the back
   with temp[j] > temp[i]

   This also means, you will try to build ans from larger idx
   to lower idx

               idx  0 1 2 3 4
say you have: temp [3 2 1 2 5]

idx val ans
 4   5  [0 0 0 0 0]
 3   2  [0 0 0 1 0] (temp[4] > temp[3], ans[3] = 1)
 2   1  [0 0 1 1 0] (temp[3] > temp[3], ans[2] = 1)
 1   2  [0 3 1 1 0] (temp[2] < temp[1], and we know ans[2] = 1
                     so first idx larger than temp[2] is 2 + ans[2] = 3
                     however, temp[3] < temp[1], so you keep checking
                     first idx larger than temp[3] is 3 + ans[3] = 4
                     and temp[4] > temp[1], so you know ans[1] = 4 - 1
 0   3  [4 3 1 1 0] (temp[0] < temp[1], and we know ans[1] = 3
                     so we check temp[1 + 3] > temp[0], we know
                     ans[0] = 4 - 0 = 4
*/

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temp) {
    const int sz = temp.size();
    std::vector<int> ans(sz, 0);
    for (int i = sz - 2; i >= 0; i--) {
      int firstLargerIdx = i + 1;
      while (temp[firstLargerIdx] <= temp[i] && ans[firstLargerIdx] != 0) {
        firstLargerIdx += ans[firstLargerIdx];
      }
      if (temp[firstLargerIdx] > temp[i]) {
        ans[i] = firstLargerIdx - i;
      }
    }
    return ans;
  }
};