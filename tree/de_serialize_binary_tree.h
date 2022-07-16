/**
Idea: preorder traversal:

       1
   2       4   -> "1 2 # 3 # # 4 5 # # #"
     3    5

When deserialize, you can just apply the recursion accordingly.
 */
class Codec {
    void preorderSerialize(TreeNode* node, std::ostringstream& os) {
        if (!node) {
            os << " #";
            return;
        }
        os << ' ' << node->val;
        preorderSerialize(node->left, os);
        preorderSerialize(node->right, os);
    }

    TreeNode* preorderDeserialize(std::istringstream& is) {
        std::string buf;
        is >> buf;
        if (buf.empty() || buf.front() == '#') {
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(buf));
        node->left = preorderDeserialize(is);
        node->right = preorderDeserialize(is);
        return node;
    }

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ostringstream os;
        preorderSerialize(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream is(data);
        return preorderDeserialize(is);
    }
};
