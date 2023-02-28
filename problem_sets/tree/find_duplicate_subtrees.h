/**
The key to make faster implementation is to "compress" the unique tree
with a representative id instead of the whole tree structure.
*/
class Solution {
 public:
  struct IdCnt {
    int id = 0;
    int count = 0;
  };
  std::unordered_map<std::string, IdCnt> seen;
  int uniqueId = 1;
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    std::vector<TreeNode*> res;
    traverse(root, res);
    return res;
  }

  int traverse(TreeNode* node, std::vector<TreeNode*>& res) {
    if (!node) {
      return 0;
    }
    std::ostringstream os;
    os << node->val;
    os << "," << traverse(node->left, res);
    os << "," << traverse(node->right, res) << '|';
    const auto subtreeStr = os.str();
    if (auto it = seen.find(subtreeStr); it != seen.end()) {
      if (++it->second.count == 2) {
        res.push_back(node);
      }
    } else {
      seen.emplace(subtreeStr, IdCnt{uniqueId++, 1});
    }
    return seen[subtreeStr].id;
  }
};