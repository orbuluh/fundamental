/*
brute force ....

all combinations of picking one value in each row
so there are n^m possibility

col 0   1   2
    1   2  [3]
    1   [5] 1


say we are doing dfs on each row,
previous column must be something affecting next row
(e.g. + score[i][col] - abs(colPrev - col))

and the column in this row affecting next row, again, during dfs, so overall
state relates to (rowIdx, prevCol)... This DFS like solution get a TLE though.

Can we do better?

As for every value in each row, it has to compare with every value in the next
row....

Consider we've got a max score for each column in row[i], with score[i]
To the next row[i + 1], the effect of score[i] should be the one giving max of
row[i + 1] + (score[i] - col_diff)

This is the place that we were checking the effect of O(col^2) to find the max
profit between any 2 cols of the i and i + 1 rows

However, there is an amazing way to find this out with O(col):

col          0   1  2  3      n - 1
score[i]:   s0 s1 s2 s3 ...   sn_1
row[i + 1]:  a  b  c  d  ...   n_1

the effect of score[i][0] = s0
  - to row[i+1][0] = a is s0 + abs(0 - 0)
  - to row[i+1][1] = a is s0 + abs(0 - 1)
              ...
  - to row[i+1][n - 1] = a is s0 + abs(0 - (n - 1))

So for each score[i][j] you can actually build an array showing the effect
counting from left of the row (and right of the row, put this later)

col            0    1   2   3        n - 1
score[i - 1]: s0  s1  s2  s3  ...   sn_1
left[i]:      s0' s1' s2' s3' ...   sn_1'

where:
- s0' = s0 + point[i][0]
- s1' = std::max(left[1 - 1] - 1, s1 + point[i][1])
- s2' = std::max(left[2 - 1] - 1, s2 + point[i][2])
...
- sk' = std::max(left[k - 1] - 1, sl_1 + point[i][k])


The critical thing is that you only check the left[k - 1] - 1 for col k
as what we store is the maximum score counting from left side. (Sort of like the
concept of prefix sum...)
So the effect of all previous column is included by the max operation


Same you can build a right[i] to show the effect from right of the row

col           0    1   2   3        n - 1
score[i - 1]: s0  s1  s2  s3  ...   sn_1
right[i]:     s0" s1" s2" s3" ...   sn_1"

where:
- sn_1" = sn_1 + point[i][n - 1]
- sn_2" = std::max(right[n - 2 + 1] - 1, sn_2 + point[i][n - 2])
...
- sn_k" = std::max(right[n - k + 1] - 1, sn_k + point[i][n - k])

Then the combined effect of all score across all columns of row[i]
to the specific column of next row[i+1][col] should equal to
std::max(left[i], right[i]) (e.g. you consider the max from left most
to the max from right most, and taking the bigger one!)
*/

class Solution {
 public:
  using DpVec = std::vector<long long>;

  DpVec calcRowPoints(const std::vector<int>& rowPt, const DpVec& prevPt) {
    const int sz = rowPt.size();
    DpVec left(sz, 0);
    DpVec right(sz, 0);
    left[0] = prevPt[0] + rowPt[0];
    right[sz - 1] = prevPt[sz - 1] + rowPt[sz - 1];
    for (int i = 1; i < sz; ++i) {
      left[i] = std::max(left[i - 1] - 1, prevPt[i] + rowPt[i]);
      int j = sz - 1 - i;
      right[j] = std::max(right[j + 1] - 1, prevPt[j] + rowPt[j]);
    }
    for (int i = 0; i < sz; ++i) {
      left[i] = std::max(left[i], right[i]);
    }
    return left;
  }
  long long maxPoints(vector<vector<int>>& points) {
    const int m = points.size();
    const int sz = points[0].size();

    DpVec dp(sz, 0);
    for (int i = 0; i < m; ++i) {
      dp = std::move(calcRowPoints(points[i], dp));
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};
