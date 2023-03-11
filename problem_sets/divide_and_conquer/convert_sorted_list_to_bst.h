/**

Below Solution_original is the more straightforward divide and conquer of
keep finding mid and break down the list, then build the tree recursively.

Here, Solution is modified from the fastest submission spotted on the OG.

The interesting part is how it maintains the "non-converted list node" and
move it in each iteration while building tree. Also, you only need to traverse
the whole list twice. First time getting the full length, second time you just
use the length's information to help you decide what to do.

Conceptually, it's like you know in-order traverse of a BST will be sorted, as
what is like in the original input. So reversely ... you know when you build
the bst recursively while dividing up number of nodes to
[left half, mid, right half], while process in such in-order order, then the
result should be what you want. Not totally intuitive but nice to know I guess.

So the process will be like:

nodeIdx: 0 1 2 3 4
  vals: [1,2,3,4,5]

(stack 0): l = 0, r = 4, mid = 2, nonConvertedHead = 1
           build its left first ...
  (stack 1): l = 0, r = 1, mid = 0, nonConvertedHead = 1
             build its left first ...
    (stack 2): l = 0, r = 0, mid = 0,
               return built TreeNode(1),  and change: nonConvertedHead = 2
  (stack 1): left subtree root TreeNode(1) is returned
             build the root (as we are doing in-order order).
             root = build TreeNode(2), and change: nonConvertedHead = 3
             then build the right subtree
    (stack 2): l = 1, r = 1, mid = 1, nonConverted = 3
               return built TreeNode(3), and change nonConvertedHead = 4
  (stack 1): connect right subtree root(3) as root(2)'s right tree
             connect left subtree  root(1) as root(2)'s left tree
             return the root(2)
(stack 0): root = build TreeNode(4), and nonConvertedHead = 5
           try to build the right subtree now
  (stack 1): l = 3, r = 4, mid = 3, nonConvertedHead = 5
             build left subtree first
    (stack 2): l = 3, r = 2, return nullptr
  (stack 1): build root TreeNode(5), nonConvertedHead = nullptr
             then build right subtree
    (stack 2): l = 4, r = 4, mid = 4, nonConvertedHead is null though
  (stack 1): left/right subtree are both nullptr, returned the TreeNode(5)
(stack 0): connects the left subtree root(2) and right subtree root(5) with
           root(4), final tree looks like:
                    4
                2       5
              1  3
**/

class Solution {
  ListNode* nonConvertedHead_ = nullptr;

 public:
  TreeNode* buildTree(int l, int r) {
    if (l > r || !nonConvertedHead_) {
      return nullptr;
    }
    int mid = l + (r - l) / 2;
    auto leftSubTree = buildTree(l, mid - 1);
    auto root = new TreeNode{nonConvertedHead_->val};
    root->left = leftSubTree;
    nonConvertedHead_ = nonConvertedHead_->next; /*the interesting change!*/
    root->right = buildTree(mid + 1, r);
    return root;
  }

  int getLen(ListNode* node) {
    int len = 0;
    while (node) {
      node = node->next;
      len++;
    }
    return len;
  }

  TreeNode* sortedListToBST(ListNode* head) {
    nonConvertedHead_ = head;
    const int n = getLen(head);
    return buildTree(0, n - 1);
  }
};

class Solution_original {
 public:
  std::tuple<ListNode*, ListNode*, ListNode*> split(ListNode* head) {
    ListNode* prev = nullptr;
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      prev = std::exchange(slow, slow->next);
      fast = fast->next->next;
    }
    // [head -> prev] [mid] [mid->next -> end]
    if (prev) {
      prev->next = nullptr;
      fast = std::exchange(slow->next, nullptr);
      return {head, slow, fast};
    } else {
      return {nullptr, head, nullptr};
    }
  }

  TreeNode* sortedListToBST(ListNode* head) { return buildTree(head); }

  TreeNode* buildTree(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    auto [l, mid, r] = split(head);
    TreeNode* root = new TreeNode{mid->val};
    root->left = buildTree(l);
    root->right = buildTree(r);
    return root;
  }
};