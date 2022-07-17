/*
The point is - set, map, multiset, multimap are sorted by keys!
multiset - same value could be inserted multiple times!
 */
class Solution {
    using Col = int;
    using Depth = int;
    std::map<Col, std::map<Depth, std::multiset<int>>> cords;

  public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root, 0, 0);
        std::vector<std::vector<int>> ans;
        int lastCol = INT_MIN;
        for (const auto& colData : cords) {
            const auto col = colData.first;
            std::vector<int> res;
            for (const auto& depthData : colData.second) {
                const auto depth = depthData.first;
                const auto& valSet = depthData.second;
                res.insert(res.end(), valSet.begin(), valSet.end());
            }
            ans.emplace_back(std::move(res));
        }
        return ans;
    }

    void inorder(TreeNode* node, int depth, int col) {
        if (!node)
            return;
        inorder(node->left, depth + 1, col - 1);
        cords[col][depth].insert(node->val);
        inorder(node->right, depth + 1, col + 1);
    }
};