class Solution {
 public:
  using Mat = vector<vector<int>>;
  using BitSet = bitset<32>;
  using BitMat = vector<BitSet>;
  int sz = 0;

  int maxOverlap(const BitMat& m1, const BitMat& m2, int rowOffset,
                 int colOffset) {
    int overlap1 = 0;  // phase 1 offset (+row, +col)
    int overlap2 = 0;  // phase 2 offset (-row, +col)
    int overlap3 = 0;  // phase 3 offset (-row, -col)
    int overlap4 = 0;  // phase 4 offset (+row, -col)
    for (int i = 0; i < sz; ++i) {
      if (i + rowOffset < sz) {
        overlap1 += ((m1[i + rowOffset] >> colOffset) & m2[i]).count();
        overlap4 += ((m1[i + rowOffset] << colOffset) & m2[i]).count();
      }
      if (i - rowOffset >= 0) {
        overlap2 += ((m1[i - rowOffset] >> colOffset) & m2[i]).count();
        overlap3 += ((m1[i - rowOffset] << colOffset) & m2[i]).count();
      }
    }
    return std::max(overlap1, std::max(overlap2, std::max(overlap3, overlap4)));
  }

  int largestOverlap(Mat& img1, Mat& img2) {
    sz = img1.size();

    BitMat m1 = std::vector<BitSet>(sz, BitSet{});
    BitMat m2 = std::vector<BitSet>(sz, BitSet{});

    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        if (img1[i][j]) m1[i].set(j);
        if (img2[i][j]) m2[i].set(j);
      }
    }

    int res = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        res = std::max(res, maxOverlap(m1, m2, i, j));
      }
    }
    return res;
  }
};

/* The much slower plain conversion code from
https://leetcode.com/problems/image-overlap/discuss/832202/Python-simple-and-clear-solution-corrected

class Solution {
public:
    using Mat = vector<vector<int>>;
    int sz = 0;

    int maxOverlap(const Mat& m1, const Mat& m2, int rowOffset, int colOffset) {
      int overlap1 = 0;  // phase 1 offset (+row, +col)
      int overlap2 = 0;  // phase 2 offset (-row, +col)
      int overlap3 = 0;  // phase 3 offset (-row, -col)
      int overlap4 = 0;  // phase 4 offset (+row, -col)
      for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
          if (i + rowOffset < sz && j + colOffset < sz) {
            overlap1 += m1[i + rowOffset][j + colOffset] & m2[i][j];
          }
          if (i - rowOffset >= 0 && j + colOffset < sz) {
            overlap2 += m1[i - rowOffset][j + colOffset] & m2[i][j];
          }
          if (i - rowOffset >= 0 && j - colOffset >= 0) {
            overlap3 += m1[i - rowOffset][j - colOffset] & m2[i][j];
          }
          if (i + rowOffset < sz && j - colOffset >= 0) {
            overlap4 += m1[i + rowOffset][j - colOffset] & m2[i][j];
          }
        }
      }
      return std::max(overlap1, std::max(overlap2, std::max(overlap3,
overlap4)));
    }

    int largestOverlap(Mat& img1, Mat& img2) {
      sz = img1.size();
      int res = 0;
      for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
          res = std::max(res, maxOverlap(img1, img2, i, j));
        }
      }
      return res;
    }
}; */