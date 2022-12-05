/* your original solution ...
- The thought was book keeping the tail of the last flatten list
- check bottom...

Here list the idea from best vote solution from:
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
and nice explanation from:
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share/146292

Idea, post order traversal and book keeping the last head visited.
then concatenate curNode->right to last head during recursive unwind

    1
   / \
  2   5
 / \   \
3   4   6

post order traversal ... 6 -> 5 -> 4
                              ^ lastHead
                                   ^ root
root->right = lastHead...

    1
   /
  2
 / \
3   4
     \
      5
       \
        6
post order traversal ... 6 -> 5 -> 4 -> 3
                                   ^ lastHead
                                        ^ root
root->right = lastHead =>

    1
   /
  2
 /
3
 \
  4
   \
    5
     \
      6
post order traversal ... 6 -> 5 -> 4 -> 3 -> 2
                                        ^ lastHead
                                             ^ root
root->right = lastHead =>

    1
   /
  2
   \
    3
     \
      4
       \
        5
         \
          6
post order traversal ... 6 -> 5 -> 4 -> 3 -> 2 -> 1
                                             ^ lastHead
                                                  ^ root
root->right = lastHead =>

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

class Solution {
    TreeNode* lastHead = nullptr;

  public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = lastHead;
        root->left = nullptr;
        lastHead = root;
    }
};

/*
your original solution ...
- The thought was book keeping the tail of the last flatten list

- if there is no left, just flatten right and the tail of the root is still the
  tail of the right

- Otherwise, try to flatten the left, and do the reconnection

class Solution {
    TreeNode* tail = nullptr;

  public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            tail = root;
            return;
        }
        if (!root->left) {
            flatten(root->right);
            return;
        }

        flatten(root->left);
        auto leftTail = tail;
        flatten(root->right);
        leftTail->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};
*/