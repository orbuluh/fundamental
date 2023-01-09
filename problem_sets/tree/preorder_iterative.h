/*
The aha point is using stack, and putting right node first.
Then it's guaranteed to pop left before right, and also left's subtree will
before right.
*/
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> res;
    if (!root) {
      return res;
    }
    std::stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      auto node = stk.top();
      stk.pop();
      res.push_back(node->val);
      if (node->right) {
        stk.push(node->right);
      }
      if (node->left) {
        stk.push(node->left);
      }
    }
    return res;
  }
};