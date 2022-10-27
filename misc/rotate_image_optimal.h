/*
By others from OJ ... need some more dig in ...
*/

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int numberoflayer = 0; numberoflayer < n / 2; numberoflayer++) {
      for (int i = 0; i < n - (numberoflayer * 2) - 1; i++) {
        swap(matrix[n - numberoflayer - i - 1][numberoflayer],
             matrix[numberoflayer][i + numberoflayer]);
      }
      for (int i = 0; i < n - (numberoflayer * 2) - 1; i++) {
        swap(matrix[n - numberoflayer - i - 1][numberoflayer],
             matrix[i + numberoflayer][n - numberoflayer - 1]);
      }
      for (int i = 0; i < n - (numberoflayer * 2) - 1; i++) {
        swap(matrix[n - numberoflayer - i - 1][numberoflayer],
             matrix[n - numberoflayer - 1][n - numberoflayer - i - 1]);
      }
    }
  }
};