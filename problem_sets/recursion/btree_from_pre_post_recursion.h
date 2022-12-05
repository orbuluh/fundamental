/*
From lee215 ...
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)

Create a node TreeNode(pre[preIndex]) as the root.

Because root node will be lastly iterated in post order,
if root.val == post[posIndex],
it means we have constructed the whole tree,

If we haven't completed constructed the whole tree,
So we recursively constructFromPrePost for left sub tree and right sub tree.

And finally, we'll reach the posIndex that root.val == post[posIndex].
We increment posIndex and return our root node.

.... lost even trying to follow one example....
... need to rethink later ...
 */
class Solution {
  int preIndex = 0;
  int posIndex = 0;

 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    TreeNode* root = new TreeNode(pre[preIndex++]);
    if (root->val != post[posIndex]) {
      root->left = constructFromPrePost(pre, post);
    }
    if (root->val != post[posIndex]) {
      root->right = constructFromPrePost(pre, post);
    }
    posIndex++;
    return root;
  }
};
