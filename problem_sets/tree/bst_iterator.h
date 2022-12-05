/*
BST: all the descendent on the left subtree are smaller than the node
     all the descendent on the right subtree are larger than the node

So you would like to delay the time you process a node till you are sure that
all the left subtree has been completed. But how? Using a stack!

Every time you encounter a new node, you put the node and all its left node
to the stack - because a node's left node should always be processed.

But when do we traverse the right node? Note that nodes under right subtree
will always have larger value than the node. So the idea is that right after we
pop a node from the stack (e.g. we traversed the node), we will encounter the
node->right as a new node, (e.g. we pushed right node and all its left node into
the stack.
 */
class BSTIterator {
  std::stack<TreeNode*> stk_;

 public:
  BSTIterator(TreeNode* root) { pushAllNewLeftNodes(root); }

  int next() {
    if (stk_.empty()) return 0;
    const auto node = stk_.top();
    stk_.pop();
    pushAllNewLeftNodes(node->right);
    return node->val;
  }

  bool hasNext() { return !stk_.empty(); }

 private:
  inline void pushAllNewLeftNodes(TreeNode* node) {
    while (node) {
      stk_.push(node);
      node = node->left;
    }
  }
};