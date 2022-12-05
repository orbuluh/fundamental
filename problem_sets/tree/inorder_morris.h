class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    auto cur = root;
    while (cur) {
      if (cur->left) {
        // Morris observation: in order traversal - once we finished
        // the whole left subtree, the next node is the cur node here.
        // And the last node of the left subtree is the right most of
        // cur's left node. So the trick is we find that last node, and
        // we make a backward connection to cur node, then we move on
        // to handle cur->left. Once we finished all, that backward
        // connection brings us back to the cur node, so we can inorder
        // output it and starts to work on right node.
        auto rightMostOfLeft = cur->left;
        while (rightMostOfLeft->right && rightMostOfLeft->right != cur) {
          rightMostOfLeft = rightMostOfLeft->right;
        }
        if (!rightMostOfLeft->right) {
          // first time travel cur, right most of left hasn't connect
          // back to cur node
          rightMostOfLeft->right = cur;  // Morris: connect back
          cur = cur->left;
        } else {  // must be equal to cur, e.g. you've done travel left
          rightMostOfLeft->right = nullptr;  // recovered the tree
          // we've done travel whole left, so we output the result
          // and start to handle right subtree of cur
          res.push_back(cur->val);
          cur = cur->right;
        }
      } else {
        // if a node doesn't have left at all, inorder we output the cur
        // and work on right
        res.push_back(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }
