/*
Idea: from
https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/discuss/154659/Divide-and-Conquer-without-Dummy-Node-Java-Solution

1. Create a linked list from recursion:
    inorder(node->left) -> node -> inorder(node->right)
2. We can do divide and conquer:
    DDL(subtree of node) =
        DDL(subtree of node->left) <-> node <-> DDL(subtree of node->right)
3. Specifically, you need to know how to combine 2 DDL, then you can combine
   the result of subproblems accordingly.
*/
class Solution {
    Node* combine(Node* dl1, Node* dl2) {
        // combine 2 double linked list
        if (!dl1)
            return dl2;
        if (!dl2)
            return dl1;
        auto dl1tail = dl1->left;
        auto dl2tail = dl2->left;
        dl1tail->right = dl2;
        dl2->left = dl1tail;
        dl2tail->right = dl1;
        dl1->left = dl2tail;
        return dl1;
    }

  public:
    Node* treeToDoublyList(Node* node) {
        // recursion return the DDL of the subtree of node
        if (!node)
            return nullptr;
        auto* leftDLL = treeToDoublyList(node->left);
        auto* rightDLL = treeToDoublyList(node->right);
        // make node itself a one node DLL ... beautiful!
        node->left = node;
        node->right = node;
        // combine the full DLL for subtree of node
        // can also do combine(combine(leftDLL, node), rightDLL);
        return combine(leftDLL, combine(node, rightDLL));
    }
};