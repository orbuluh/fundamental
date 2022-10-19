/*
The segment tree implementation.

Query result should be the unpainted portion of the range.
Store the current painted count in each node.
If nodeR - nodeL + 1 == node value, it means full range is painted - we don't
need to paint further.

When query range is partially overlapped with node range - we check what's the
unpainted count from left and right respectively. Then the sum is what we are
going to return for the node. But note that we added such value to the node's
value - as node's value represents the amount we've painted for the range!

This is the slower than the jump line solution, but just showing a different
usage of segment tree!
*/

class SegmentTree {
  std::vector<int> allNodes_;  // value: painted count
 public:
  SegmentTree(int fullRange) : allNodes_(fullRange * 4, 0) {}

  int paint(int queryL, int queryR, int rangeL, int rangeR, int nodePos) {
    const auto rangeCnt = rangeR - rangeL + 1;
    if (allNodes_[nodePos] == rangeCnt) return 0;  // already paint full range

    if (queryL <= rangeL && queryR >= rangeR) {  // query full cover node range
      const auto notPaintYet = rangeCnt - allNodes_[nodePos];
      allNodes_[nodePos] = rangeCnt;
      return notPaintYet;
    } else if (queryL > rangeR ||
               queryR < rangeL) {  // query outside node range
      return 0;
    }

    // query partially overlapped with range
    int mid = rangeL + (rangeR - rangeL) / 2;
    int lUnPaint = paint(queryL, queryR, rangeL, mid, 2 * nodePos + 1);
    int rUnPaint = paint(queryL, queryR, mid + 1, rangeR, 2 * nodePos + 2);
    allNodes_[nodePos] += (lUnPaint + rUnPaint);
    return lUnPaint + rUnPaint;  // not return allNodes_[nodePos]
  }
};

class Solution {
 public:
  vector<int> amountPainted(vector<vector<int>>& paint) {
    int rangeMax = 0;
    for (const auto& p : paint) {
      rangeMax = std::max(rangeMax, p[1]);
    }
    SegmentTree segTree(rangeMax);
    std::vector<int> res;
    for (const auto& p : paint) {
      res.push_back(segTree.paint(p[0], p[1] - 1, 0, rangeMax, 0));
    }
    return res;
  }
};