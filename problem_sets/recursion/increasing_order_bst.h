class Solution {
    /*
    Idea: linkedList(root) =   linkedList(root.left)
                             + root
                             + linkedList(root.right)
    E.g. linkedList is a recursive function to convert a subtree
         to a linked list

    Observation:
    1. linkedList(node->left)'s end is node
    2. linkedList(node)'s end is the same as linkedList(node->right)'s end
    3. you will need the information of the end of a linked list to concatenate
       to the head of linkedList(parent->right).
    4. linkedList(root)'s tail is a nullptr.
    5. node->left should reset to nullptr as problem requested.
    6. The terminate condition is actually the hardest part here. Need to think
       about your recursion:
       - You are trying to return the head of the full linked list of a subtree
       - The parent of the subtree will be concatenated to the end of
         the linked list, on the end of the right most leaf of the subtree.
       - You are not returning the right most leaf of the subtree, so you expect
         to pass it in so it can concatenate accordingly.
       - But how? It will be in the
         node->right = linkedList(node->right, listTailOfNode)
         call, where when node->right of node is nullptr, it returns the
        listTailOfNode and concatenate to node->right!
    */
  public:
    TreeNode* increasingBST(TreeNode* root) {
        return linkedList(root, nullptr);
    }

    TreeNode* linkedList(TreeNode* node, TreeNode* listTailOfNode) {
        if (!node) return listTailOfNode; // obs. 6
        // node must be the left linked list's end
        auto listHead = linkedList(node->left, node); // obs. 1
        node->left = nullptr;
        // original node's end will also be right node linked list's end
        node->right = linkedList(node->right, listTailOfNode); // obs. 2, 3
        return listHead;
    }
};