/**

As how heap is implemented, say root node idx 0,

and say a node with idx x, we know that its left child is at
2 * x + 1, and its right child is at 2 * x + 2

The critical thing for this problem is that you will easily get
overflow as the test case has deep tree.

One thing to realize is that you can always offset the index
with the first node on the level. And the remaining will still
be the same ...

        say (number is node idx)
                0
           1         2
             4         6
            9            14
          19               30  width = 30 - 19 + 1 = 12

        then it should be  the same if you try to do an offset
        in each level, and use the offset'ed index for next level
        calculation!

                0
           1-1        2-1
             2-2        4-2
            1-1            6-1
           1-1               12-1  width = 11 - 0 + 1  = 12
 */

class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    std::vector<std::pair<TreeNode*, long>> toTravel = {{root, 0}};
    std::vector<std::pair<TreeNode*, long>> nxtTravel = {};
    long maxWidth = 0;
    while (!toTravel.empty()) {
      nxtTravel.clear();
      int offset = toTravel.front().second;
      const int sz = toTravel.size();
      maxWidth = std::max(maxWidth,
                          toTravel.back().second - toTravel.front().second + 1);
      for (auto [node, idx] : toTravel) {
        idx = idx - offset + 1; // critical so we won't overflow!!
        if (node->left) {
          nxtTravel.push_back({node->left, idx * 2 + 1});
        }
        if (node->right) {
          nxtTravel.push_back({node->right, idx * 2 + 2});
        }
      }
      std::swap(toTravel, nxtTravel);
    }
    return maxWidth;
  }
};