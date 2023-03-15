/*
BFS way 1 (your brute force... logic is harder to think correctly though):

- if it's not the parent of last level, we check both left and right
- if it's parent of last level, we check continuous through ...
  -> if right && !left => false
     if have seen right == nullptr, you should not see other next level node
     (above observation is critical...)

BFS way 2 (@lee215):

- BFS till we hit the first node without either left or right
- Then for the remaining node in the queue, non of them should have children

  imagine      ==> when you bfs, you break when inserting node 4
     1             in the queue, there is still 3. So when you pop 3
   2   3           and realize there is still children, it's not complete.
  4      5

DFS way (@votrubac):

- Idea: DFS to find the height. The first time you are hitting null during DFS,
        you find the height h. And then all subtree should have same height ...
        until the first time it's seeing a subtree with height == h - 1. And
        since then, the height should always be h - 1
 */

class Solution_DFS {
  int height = 0;
  bool haveSeenValidIncomplete = false;

 public:
  bool isCompleteTree(TreeNode* root, int h = 0) {
    if (!root) {
      if (height == 0) {
        height = h;
      } else if (h == height - 1) {
        haveSeenValidIncomplete = true;
      }
      // once you see a node with only height - 1
      // all the subtree can only have height - 1
      return h == height - haveSeenValidIncomplete;
    }
    return isCompleteTree(root->left, h + 1) &&
           isCompleteTree(root->right, h + 1);
  }
};

class Solution_BFS_2 {
 public:
  bool isCompleteTree(TreeNode* root) {
    std::queue<TreeNode*> queue;
    auto popTop = [&]() {
      auto node = queue.front();
      queue.pop();
      return node;
    };

    queue.push(root);
    while (!queue.empty()) {
      auto node = popTop();
      if (!node->left) {
        if (node->right) {
          return false;
        }
        break;
      }
      queue.push(node->left);
      if (!node->right) {
        break;
      }
      queue.push(node->right);
    }
    while (!queue.empty()) {
      auto node = popTop();
      if (node->left || node->right) {
        return false;
      }
    }
    return true;
  }
};

class Solution_BFS_1 {
  int height(TreeNode* node) {
    int h = 0;
    while (node) {
      h++;
      node = node->left;
    }
    return h;
  }

 public:
  bool isCompleteTree(TreeNode* root) {
    int h = height(root);
    std::vector<TreeNode*> queue;
    // queue.reserve(1 << h);
    std::vector<TreeNode*> nxtQueue = queue;
    queue.push_back(root);
    int level = 0;
    while (!queue.empty()) {
      level++;
      nxtQueue.clear();
      bool haveSeenNullRight = false;
      for (auto node : queue) {
        if (level < h - 1) {
          if (!node->left || !node->right) {
            return false;
          }
        } else {
          if (haveSeenNullRight && (node->left || node->right)) {
            return false;
          }
          if (node->right && !node->left) {
            return false;
          }
          if (!node->right) {
            haveSeenNullRight = true;
          }
        }
        if (node->left) {
          nxtQueue.push_back(node->left);
        }
        if (node->right) {
          nxtQueue.push_back(node->right);
        }
      }
      std::swap(nxtQueue, queue);
    }
    return true;
  }
};

using Solution = Solution_DFS;