/*

Path doesn't need to be follow the tree order as the question suggests.
Can you still follow the tree order and do recursion, and find out the answer?

Actually you can.

The idea is, for a node and its subtree, it can only be partial of the path with
its parent in the case that no more than one child is taken.

            P
         N
       L   R

--> think about the subtree of N, if optimal path contains P and N, then optimal
path cannot include both L and R.

So the idea is, when you recursion N, there could be one possible max created
by recur(L) + N + recur(R), which is a path that doesn't include P. Also, you
should return the max of N, N + L, N + R back to P, as they are all viable to
construct a path with P!

    -1
  5
6   -1

 */
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    dfs(root, maxSum);
    return maxSum;
  }
  int dfs(TreeNode* node, int& maxSum) {
    if (!node) {
      return 0;
    }
    const int leftVal = std::max(0, dfs(node->left, maxSum));
    const int rightVal = std::max(0, dfs(node->right, maxSum));
    // path with left, node, right, parent of node can't include this one
    maxSum = std::max(maxSum, node->val + leftVal + rightVal);
    // Note that as we make sure leftVal and rightVal >= 0. Say if rightVal is
    // larger than 0, then node + left can't be the best answer. if rightVal is
    // smaller than 0, we capture the case that node + left already in above
    // max update. So we don't need to do partialPath update like
    // maxSum = std::max(maxSum, std::max(leftVal, rightVal) + node->val) below.
    return std::max(leftVal, rightVal) + node->val;
  }
};