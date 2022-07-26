class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        // the most critical idea - if root is either p or q, be there the
        // other node underneath or not, it's always be the node to return
        if (root == p || root == q)
            return root;
        auto fromLeft = lowestCommonAncestor(root->left, p, q);
        auto fromRight = lowestCommonAncestor(root->right, p, q);
        if (fromLeft && fromRight)
            return root;
        // if !fromLeft && !fromRight - will return nullptr
        return fromLeft ? fromLeft : fromRight;
    }
};