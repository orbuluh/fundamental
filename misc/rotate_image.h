/*
Idea: the easiest way is transpose (\ direction flip) then flip left and right

1 2 3  (T\)   1 4 7   (F)  7 4 1
4 5 6   -->   2 5 8   -->  8 5 2
7 8 9         3 6 9        9 6 3

This will likely be clean as for transpose, you can do:
    - for i > j ... mat[i][j] = mat[j][i]
Then flip left and right:
    - for j < n/2 ... mat[i][j] = mat[i][sz - 1 - j]

The question is ... what if you think the order in a wrong way?
E.g. during a mock interview, you were thinking to do flip left and right
first, then do another direct (/ direction flip) of transpose.

1 2 3  (F)   3 2 1   (T/)  7 4 1
4 5 6  -->   6 5 4    -->  8 5 2
7 8 9        9 8 7         9 6 3

How do you do the / direction flip?

Overall observe: 2 is going to flip with 4 in the last step.
->|
3 2 1
6 5 4 T
9 8 7 |
Where is 2? It's i away from row 0, and j away from col 0
Where is 4? It's j away from row sz - 1, and i away from col sz - 1

So you will be swapping: mat[i][j] = mat[sz - 1 - j][sz - 1 - i]
Double check, 6 @(1, 0) need to swap with 8 @(2, 1) == (2 - 0, 2 - 1) exactly

But then another complexity is making sure you are swapping the right elements

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {

--> this swap (0, 1) .. .(0, n - 1),
              (1, 2) .... (1, n - 1)
    so this is swapping the top right with bottom left, not what we want here

to swap the top left with down right, observe you are looking:
    (0, 0) ... (0, n - 2)
    (1, 0) ... (1, n - 3)
    ....
so the loop should be
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n - i; ++j) {

So overall this might be one way to think about how to do such indices
manipulation!
*/

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // \ transpose first
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
    // then <-> flip
    for (int col = 0; col < n / 2; ++col) {
      for (int row = 0; row < n; ++row) {
        std::swap(matrix[row][col], matrix[row][n - 1 - col]);
      }
    }
  }
};

/* The much more confusing way you happened to be trying during mock interview
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // <-> flip first
    for (int col = 0; col < n / 2; ++col) {
      for (int row = 0; row < n; ++row) {
        std::swap(matrix[row][col], matrix[row][n - 1 - col]);
      }
    }
    // then / transpose:
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n - i; ++j) {
        std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
      }
    }
  }
}; */