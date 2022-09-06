class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    // at this point, if root->left || root->right, below must have one
    // so you don't even need to check root->left->val or root->right->val
    if (root->val || root->left || root->right) return root;
    return nullptr;
  }
};