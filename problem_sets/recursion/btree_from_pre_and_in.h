
class Solution {
  public:
    /* Idea ...
    Preorder must hit the root first, while inorder going into the left subtree.
    pre: [3,9,8,6,20,15,7]
          P.......P'
    in:  [8,9,6,3,15,20,7]
          <-L-> I <--R-->
    So 3 from pre must be the root, and if you search 3 in inorder, the left
    subtree of root 3 must be before I, the index of root 3 in inorder.

    And the right subtree must be the right side after the 3 of the inorder tree

    The question is, from above example, say left root is at position I in
    inorder, does it mean that the root of right subtree must be at position
    I + 1 = P' in preorder? Actually no ...consider tree:
         1
       2      preorder: [1, 2, 3]
         3    inorder:  [2, 3, 1]

    --> [1, 2, 3]   L   [-, 2, 3]
         P         -->      P
        [2, 3, 1]       [2, 3, -]
               I         I I+1   --> P' (= I + 1) == P, which cause an infinite
                                     loop when trying to get right subtree of 2

    The correct way is using the knowledge of how many nodes are in the left
    subtree - and how many P should move when doing the right subtree should
    be equal to the root position plus how many node in the left subtree!
    */
    std::unordered_map<int, int> inOrderIdx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inOrderIdx[inorder[i]] = i;
        }
        return buildSubTree(0, 0, preorder.size() - 1, preorder, inorder);
    }

    TreeNode* buildSubTree(int pIdx, int iBegin, int iEnd,
                           const std::vector<int>& pre,
                           const std::vector<int>& in) {
        if (pIdx >= pre.size() || iBegin > iEnd)
            return nullptr;
        auto* root = new TreeNode(pre[pIdx]);
        const auto inIdx = inOrderIdx[root->val];
        const auto leftNodeCnt = inIdx - iBegin;
        root->left = buildSubTree(pIdx + 1, iBegin, inIdx - 1, pre, in);
        root->right = buildSubTree(pIdx + leftNodeCnt + 1, inIdx + 1, iEnd, pre, in);
        return root;
    }
};