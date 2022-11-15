/*

https://leetcode.com/problems/count-complete-tree-nodes/discuss/61958/Concise-Java-solutions-O(log(n)2)

Stefan's way to do this with O(log(n) * log(n))

The intuition is that if right subtree's height is one less than root tree's
height, you are sure that left subtree must be a full tree. But you are not sure
if right subtree is full (it just has its left most hitting the last row)

For example: the right subtree(3) isn't full, but its height is equal to root's
height - 1. So you are sure that left subtree(2) must be full (with height =
root height - 1). And you can apply recursion on the right.

      1
   2     3
  4 5   6

And consider other case: if right subtree(3)'s height is not equal to root's
height, given the definition of complete tree, you know right subtree must be
a full tree (with height = root height - 2) itself. And somewhere in the left
subtree isn't full. And you can apply recursion on the left.

      1
   2     3
  4 5
*/

class Solution {
public:
    int getHeight(TreeNode* node) {
      int height = 0;
      while (node) {
        height++;
        node = node->left;
      }
      return height;
    }
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      int rootH = getHeight(root);
      int rightH = getHeight(root->right);
      if (rootH == rightH + 1) {
        // left subtree must be full with same height, but not sure right
        // subtree is full
        return 1 + ((1 << rightH) - 1) + countNodes(root->right);
      }
      // right subtree must be full with one less level, but not sure left
      // subtree is full
      return 1 + countNodes(root->left) + ((1 << rightH) - 1);
    }
};

/*

Another way that you did

A full (not complete) binary tree with height h has 2^height - 1 nodes
To the end, single node of leaf is also a full binary tree itself.

How to decide if it's full? If left most tree has same height as right most
tree. So we can basically build up the recursion with this intuition.

Note that you are only checking leftMost and rightMost

So for example:
      1
   2     3
  4 5   6

--> leftMostH is 3, rightMostH is 2, but it doesn't mean right subtree is full

--> so NOT that when leftMostH != rightMostH, you can always assume right tree
is full.

Same, you also can't assume when leftMostH != rightMostH, left tree is full.

      1
   2     3
  4


Given the fact that once you find it's a full tree, you don't need to recursion
down ... Overall the complexity should be O(log(n) * log(n)) (?)

class Solution {
public:
    int getHeight(TreeNode* node, bool isLeft) {
      int height = 0;
      while (node) {
        height++;
        node = isLeft? node->left: node->right;
      }
      return height;
    }
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      int leftMostH = getHeight(root, true);
      int rightMostH = getHeight(root, false);
      if (leftMostH == rightMostH) {
        return (1 << leftMostH) - 1;
      }
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

*/