/**

DFS digs down a path and record the max and min

It is good to update the min max with the node val that you just traversed,
as when going down further, the node must be on the path.
*/

class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
  }

  int dfs(TreeNode* node, int minVal, int maxVal) {
    if (!node) return 0;
    minVal = std::min(node->val, minVal);
    maxVal = std::max(node->val, maxVal);
    int diff = maxVal - minVal;
    diff = std::max(diff, dfs(node->left, minVal, maxVal));
    diff = std::max(diff, dfs(node->right, minVal, maxVal));
    return diff;
  }
};