/*
you don’t need to find the leftMost to start to decreasing k, as if
you always do inorder, the time it traverse to the node is the time
it should reduce k.
*/
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) { return inorder(root, k); }

  int inorder(TreeNode* node, int& k) {
    if (!node || !k) return -1;
    const auto resFromLeft = inorder(node->left, k);
    return k == 0 ? resFromLeft
                  : (--k == 0 ? node->val : inorder(node->right, k));
  }
};