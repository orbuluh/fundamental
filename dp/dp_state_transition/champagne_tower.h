/*
Why is this a DP problem?


        [0,0]
    [1,0]   [1,1]
[2,0]   [2,1]   [2,2]

the 3 cup will be something like above

so you can imagine in general,

cup[i][j] will be filled by the remaining of

  cup[i - 1][j - 1] / 2
+ cup[i - 1][j] / 2

(if there is any remaining)

So it's like pour 4, you can maintain the water going into each level

                [4]
     [3/2]               [3/2]      --> 3 from 4 - 1
[0.5/2]  [0.5/2 + 0.5/2]     [0.5/2]  --> 0.5 from 1.5 - 1

You can basically simulate this process accordingly. And as long as a cut
encounters more than 1 from previous remaining, it will be fulled. So if it's
queried, it should return 1.0. Otherwise what is in the glass should be returned
*/

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    if (poured <= 1) {
      return (query_row == 0 && query_glass == 0 ? poured : 0.0);
    }
    if (query_row == 0) {
      return poured <= 1 ? poured : 1.0;
    }
    std::vector<double> prevCup = {1.0 * poured};
    for (int row = 1; row <= query_row; ++row) {
      const int cupCnt = row + 1;
      std::vector<double> cups(cupCnt, 0);
      for (int col = 0; col < cupCnt; ++col) {
        // fill the cup from prev row left
        if (col != 0 && prevCup[col - 1] > 1.0) {
          cups[col] += (prevCup[col - 1] - 1.0) / 2.0;
        }
        // fill the cup from prev row right
        if (col != cupCnt - 1 && prevCup[col] > 1.0) {
          cups[col] += (prevCup[col] - 1.0) / 2.0;
        }
        if (row == query_row && col == query_glass) {
          return cups[col] >= 1.0 ? 1.0 : cups[col];
        }
      }
      std::swap(prevCup, cups);
    }
    return 0.0;
  }
};