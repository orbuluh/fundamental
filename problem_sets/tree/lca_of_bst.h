/*
observation:

1. BST: leftNode < root, rightNode > root.
2. LCA node must
    (1) >= small tgt node
    (2) <= big tgt node

3. if node->val > p->val && node->val > q->val,
   node can't be LCA, and LCA should be under node->left
4. if node->val < p->val && node->val < q->val,
   node can't be LCA, and LCA should be under node->right
5. OTHERWISE, because LCA is guaranteed to exist -
   LCA MUST not under the node, and the node should be the LCA.
*/

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};