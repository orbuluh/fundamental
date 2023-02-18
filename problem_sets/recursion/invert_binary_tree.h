class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return root;
    }
    auto tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;
    return root;
  }
};