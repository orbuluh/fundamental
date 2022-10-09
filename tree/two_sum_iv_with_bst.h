/*
Idea - BST iterator implementation basically gives you the next bigger number
in BST. And similarly you can do a reverse way of iterator to give you the next
smaller number.

So the idea is maintaining 2 stack for next bigger number (increasing stack) and
next smaller number (decreasing stack) - then just add the top of the stack as
the node it's going to traverse and determine if we are going to traverse to get
a bigger number or lower.

As the stack will only stores the height of the tree, the space complexity is
expected to be O(logn), which is better than the naive recursion + hashmap way
but time complexity is still O(n) basically
*/
class Solution {
 public:
  void iterateNewNode(std::stack<TreeNode*>& stk, TreeNode* node, bool isInc) {
    while (node) {
      stk.push(node);
      node = isInc ? node->left : node->right;
    }
  }
  bool findTarget(TreeNode* root, int k) {
    std::stack<TreeNode*> incStk;
    iterateNewNode(incStk, root, true);
    std::stack<TreeNode*> decStk;
    iterateNewNode(decStk, root, false);
    while (!incStk.empty() && !decStk.empty() && incStk.top() != decStk.top()) {
      const int sum = incStk.top()->val + decStk.top()->val;
      if (sum == k) {
        return true;
      } else if (sum < k) {
        auto node = incStk.top();
        incStk.pop();
        iterateNewNode(incStk, node->right, true);
      } else {
        auto node = decStk.top();
        decStk.pop();
        iterateNewNode(decStk, node->left, false);
      }
    }
    return false;
  }
};