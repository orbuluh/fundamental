/*
inorder traversal gives you sorted value, min diff must exist between 2 sorted
value. The issue is that you need to keep track of previous loaded value while
doing the traversal. And therefore, you need to keep track of whether you've
seen the first value. Then thinking about recursion, in each iteration, we are
just doing an update with difference of previous value.
*/

class Solution {
  bool init = false;
  int preVal = 0;
  int minDiff = INT_MAX;

 public:
  int minDiffInBST(TreeNode* root) {
    inorder(root);
    return minDiff;
  }

  void inorder(TreeNode* node) {
    if (!node) {
      return;
    }
    inorder(node->left);
    if (init) {
      minDiff = std::min(minDiff, node->val - preVal);
    } else {
      init = true;
    }
    preVal = node->val;
    inorder(node->right);
  }
};