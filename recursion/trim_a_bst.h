class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return root;
        // Trim first will make the solution so much clean!!!!
        // check your first implementation....
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root->val < low ? root->right
                               : (root->val > high ? root->left : root);
    }
};