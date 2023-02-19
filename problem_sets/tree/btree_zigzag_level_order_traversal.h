/*
Ideal, always create level left to right, read the value reversely if reverse
flag is false. Use vector to mimic queue
*/
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    std::vector<TreeNode*> cur;
    std::vector<TreeNode*> nxt;
    if (root) {
      cur.push_back(root);
    }
    bool reverse = false;
    while (!cur.empty()) {
      nxt.clear();
      res.push_back({});
      for (auto node : cur) {
        if (!reverse) {
          res.back().push_back(node->val);
        }
        if (node->left) nxt.push_back(node->left);
        if (node->right) nxt.push_back(node->right);
      }
      if (reverse) {
        for (int i = cur.size() - 1; i >= 0; --i) {
          res.back().push_back(cur[i]->val);
        }
      }
      reverse = !reverse;
      std::swap(nxt, cur);
    }
    return res;
  }
};