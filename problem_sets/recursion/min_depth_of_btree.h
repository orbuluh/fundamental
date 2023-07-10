class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (root->left == nullptr || root->right == nullptr)
      return std::max(l, r) + 1;
    return std::min(l, r) + 1;
  }
};