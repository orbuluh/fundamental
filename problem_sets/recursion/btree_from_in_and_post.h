/*
postorder traverse travel with left -> right -> root recursively.

So you can imagine the last node in postorder vector will be the tree root.

once you know the tree node, and check the inorder vector. You will see that
(the remaining of) inorder vector is separate to 2 parts by the root val.
The left part being the left subtree, and the right part being the right subtree


            3        inorder =   [6 4 7 3 8 5 9]
         4    5      postorder = [6 7 4 8 9 5 3]
        6 7  8  9


postorder = [6 7 4 8 9 5 3]
                         ^ postIdx get root val 3
inorder =   [6 4 7 3 8 5 9]
                   ^  anchor root val in inorder

            ==> [6 4 7] is left tree of 3
                [8 5 9] is right tree of 3

As postorder build left -> right -> root

once you pulled out the root, postIdx - 1 should point to the head of root's
right subtree. So you rebuild the tree recursively, through building right tree
first.

Noted that postIdx is passed in by reference to keep updating while rebuilding

Build right of node 3
  postorder = [6 7 4 8 9 5 3]
                        ^ postIdx get root val 5
  inorder of right: [8 5 9]
                      ^   anchor root in inorder

Build right of node 5
  postorder = [6 7 4 8 9 5 3]
                      ^ postIdx get root val 5
  inorder of right [9]
  return and we now rebuild  5
                               9
Build left of node 5
  postorder = [6 7 4 8 9 5 3]
                     ^ postIdx get root val 8
  inorder of left [8]
  return and we now rebuild  5
                            8  9
subtree at node 5 is returned as right of node 3
now we build left of node 3:
  postorder = [6 7 4 8 9 5 3]
                   ^ postIdx get root val 5
  inorder of left: [6 4 7]
                      ^   anchor root in inorder

  ...same process as above to complete the left subtree accordingly...
*/


class Solution {
 public:
  std::unordered_map<int, int> inorderIdx;
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    const int sz = inorder.size();
    for (int i = 0; i < sz; i++) {
      inorderIdx[inorder[i]] = i;
    }
    int postIdx = sz - 1;
    return build(inorder, postorder, 0, sz - 1, postIdx);
  }

  TreeNode* build(vector<int>& in, vector<int>& post, int inS, int inE,
                  int& postIdx) {
    if (inS > inE) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(post[postIdx--]);
    int inIdx = inorderIdx[root->val];
    root->right = build(in, post, inIdx + 1, inE, postIdx);
    root->left = build(in, post, inS, inIdx - 1, postIdx);
    return root;
  }
};