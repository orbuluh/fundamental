/*
Recursion -> only leaf node should return the accumulated path value

    1
  2      --> return 12

    1
      3  --> return 13

    1
  2   3  --> return 25

When a node only have one children, what is returned is from the recursion on
the children. The other branch should have no contribution of the returned
value (which you did wrong originally). Why? only leaf node should return value.
And a node with one child is not leaf node, so it should only return the result
from the recursive result of the child node.
*/

class Solution {
 public:
  int sumNumbers(TreeNode* root, int parentVal = 0) {
    if (!root) {
      return 0;
    }
    const int curVal = parentVal * 10 + root->val;
    if (!root->left && !root->right) {
      return curVal;
    }
    return (root->left ? sumNumbers(root->left, curVal) : 0) +
           (root->right ? sumNumbers(root->right, curVal) : 0);
  }
};