class Solution {
  /*
  The idea is like trapping rain water, but now, we are marking:

  for a '.' position, what is the force it's going to take and how far is it,
  separately using 2 arrays, rForce and lForce, where each element mark
  the distance of the force:

  example       ". L . R . . . L R . . L . ."
                       ------>   ---->
  The 'rForce': [0,0,0,0,1,2,3,0,0,1,2,0,0,0]
                 <--     <------   <----
  The 'lForce': [1,0,0,0,3,2,1,0,0,2,1,0,0,0]

  So we build the rForce from left to right and lForce right to left. (Just like
  how the force should apply). If dom[i] has fallen already, there is no force.
  Otherwise we record the distance of the force accordingly.

  Then we build the result as follows:

  - if dom[i] is not '.', nothing has changed.
  - if lForce[i] == rForce[i], be it be both 0 or both some value, it means the
    force is cancelled out, so nothing has changed as well
  - lForce[i] < rForce[i] - it means there is a L that is more close to i
    than there is a R, so the point should changed to L
  - otherwise we should change to R as there is a R closer to i

  The 'rForce': [0,0,0,0,1,2,3,0,0,1,2,0,0,0]
  The 'lForce': [1,0,0,0,3,2,1,0,0,2,1,0,0,0]
  result:       "L L . R R . L L R R L L . ."
  */
 public:
  string pushDominoes(string dom) {
    auto sz = dom.size();
    std::vector<int> rForce(sz, 0);
    for (int i = 0; i < sz; ++i) {
      if (dom[i] == 'R') {
        int distance = 0;
        while (i + 1 < sz && dom[i + 1] == '.') {
          rForce[++i] = ++distance;
        }
      }
    }
    std::vector<int> lForce(sz, 0);
    for (int j = sz - 1; j >= 0; --j) {
      if (dom[j] == 'L') {
        int distance = 0;
        while (j - 1 >= 0 && dom[j - 1] == '.') {
          lForce[--j] = ++distance;
        }
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (dom[i] != '.') continue;
      if (lForce[i] == rForce[i]) continue;
      if (lForce[i] == 0) {
        dom[i] = 'R';
      } else if (rForce[i] == 0) {
        dom[i] = 'L';
      } else {
        dom[i] = lForce[i] < rForce[i] ? 'L' : 'R';
      }
    }

    return dom;
  }
};