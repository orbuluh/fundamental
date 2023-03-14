class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    return !root || isSymmetric(root->left, root->right);
  }
  bool isSymmetric(TreeNode* node1, TreeNode* node2) {
    if ((!node1) && (!node2)) {
      return true;
    }
    if ((node1 && node2) && node1->val == node2->val) {
      return isSymmetric(node1->left, node2->right) &&
             isSymmetric(node2->left, node1->right);
    }
    return false;
  }
};