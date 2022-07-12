class Solution {
    /*
    Idea: memorization on sub completed tree!
    n = 7, it can divide to:
    (1): 1 + root + 5
    (2): 3 + root + 3
    (3): 5 + root + 1
    (completed binary tree must be odd, so we won't have 2 + root + 5)
    and the possibility of 5 node can be reused in case (1) and (3)!
    */
    TreeNode* clone(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        auto rootCpy = new TreeNode{};
        rootCpy->left = clone(root->left);
        rootCpy->right = clone(root->right);
        return rootCpy;
    }

  public:
    static std::unordered_map<int, std::vector<TreeNode*>> cache;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0)
            return {};
        auto it = cache.find(n);
        if (it != cache.end())
            return it->second;
        if (n == 1)
            return cache[1] = {new TreeNode()};
        std::vector<TreeNode*> ans;
        for (int leftCnt = 1; leftCnt < n - 1; leftCnt += 2) {
            int rightCnt = n - leftCnt - 1; // -1 for root node
            auto leftCombination = allPossibleFBT(leftCnt);
            auto rightCombination = allPossibleFBT(rightCnt);
            for (auto leftRoot : leftCombination) {
                for (auto rightRoot : rightCombination) {
                    TreeNode* root = new TreeNode();
                    root->left = clone(leftRoot);
                    root->right = clone(rightRoot);
                    ans.push_back(root);
                }
            }
        }
        return cache[n] = std::move(ans);
    }
};
std::unordered_map<int, std::vector<TreeNode*>> Solution::cache;