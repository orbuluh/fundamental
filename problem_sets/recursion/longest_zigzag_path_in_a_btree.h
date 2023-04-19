/*

The beauty of this recursion is to realize that each node can be the root node
of a path. However, each node can either be left or right child of its parent.

So when we update max, we consider the node to be the root node of a path. E.g.
the node itself has no orientation, we can just use 1 + result from child.

But when we return back to parent, we need to know if we treat this node as a
left child or right child.
*/

class Solution {
  int longestSeen = 0;

 public:
  int longestZigZag(TreeNode* root) {
    getZigZagLen(root, true /*doesn't matter*/);
    return longestSeen;
  }

  int getZigZagLen(TreeNode* node, bool thisNodeAsLeft) {
    if (!node) {
      return -1;
    }
    const int fromL = getZigZagLen(node->left, true);
    const int fromR = getZigZagLen(node->right, false);
    longestSeen = std::max(longestSeen, 1 + std::max(fromL, fromR));
    return 1 + (thisNodeAsLeft ? fromR : fromL);
  }
};
