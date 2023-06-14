/**
in order traversal should be in sequence. Note how to do this iteratively.
root stores a node that we jsut meet. (But not yet "travelled" as we haven't
search its left yet.). And everytime we meet a node the first time, we push it
to stack and go to its left.

When root is null, which means we've arrived the left most node, we can start
to pop from the stack. The node pop'ing from the stack means that we should have
travelled all its left, and it's now its turn. We do the calculation for the
node, and then point root to its right. And now root will be something we just
meet the first time, so do the same thing as before...

You can also use morris, but this is the better version of non-morris iterative
in-order traversal!
*/

class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    std::stack<TreeNode*> toTravel;
    bool foundFirst = false;
    int prevVal = 0;
    int minDiff = INT_MAX;
    while (root || !toTravel.empty()) {
      if (root) {
        toTravel.push(root);
        root = root->left;
      } else {
        root = toTravel.top();
        toTravel.pop();
        if (foundFirst) {
          minDiff = std::min(minDiff, std::abs(root->val - prevVal));
        } else {
          foundFirst = true;
        }
        prevVal = root->val;
        root = root->right;
      }
    }
    return minDiff;
  }
};
