/*
You could do this in a way that you exam all the value in the recursion boundary
and check if the value are the same, then get deeper recursion if it's not.
But by doing so - you are wasting a lot of time to do repeated comparison.
Check bottom for your original implementation.

The quicker implementation is using the fact that
- For all the val 0 leafs are the same with each other, so does val 1 leafs.
  So we can make some static Node to represent it without keeping to allocate
  them.
- When the requested range in the recursion is 1, it must be a leaf
  Otherwise, a node is a leaf only if recursion told me that all the four
  children are exactly the same. (As all zero leaf and one leaf are the same
  static member we pre-allocated). Why? if any of the children is not the same,
  it must means that in the range of recursion, the value must not be all the
  same.

  (E.g. you dfs and construct the child first - then decide the root is a leaf
   after the recursion return)
*/

class Solution {
  static Node LeafFalse;
  static Node LeafTrue;

 public:
  Node* construct(vector<vector<int>>& grid) {
    return construct(grid, 0, 0, grid.size());
  }

  Node* construct(const vector<vector<int>>& grid, int r, int c, int sz) {
    if (sz == 1) {
      return grid[r][c] ? &LeafTrue : &LeafFalse;
    }
    const int hSz = sz / 2;
    auto tl = construct(grid, r, c, hSz);
    auto tr = construct(grid, r, c + hSz, hSz);
    auto bl = construct(grid, r + hSz, c, hSz);
    auto br = construct(grid, r + hSz, c + hSz, hSz);
    // NOT: if (tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
    if (tl == tr && tr == bl && bl == br) {
      return tl;
    }
    return new Node{false, false, tl, tr, bl, br};
  }
};
Node Solution::LeafFalse{false, true};
Node Solution::LeafTrue{true, true};

/*

// Original implementation, you are repeatedly checking the isLeaf while dfs'ing
// also making lots of unnecessary allocation of "leaf zero" and "leaf true".

Node* construct(vector<vector<int>>& grid) {
  return construct(grid, 0, grid[0].size() - 1, 0, grid.size() - 1);
}

Node* construct(const vector<vector<int>>& grid, int l, int r, int t, int b) {
  const bool isLeaf = [&]() {
    for (int i = t; i <= b; ++i) {
      if (!std::all_of(grid[i].begin() + l, grid[i].begin() + r + 1,
                       [&](int val) { return val == grid[t][l]; })) {
        return false;
      }
    }
    return true;
  }();

  auto root = new Node{static_cast<bool>(grid[t][l]), isLeaf};
  if (!isLeaf) {
    int colMid = l + (r - l) / 2;
    int rowMid = t + (b - t) / 2;
    root->topLeft = construct(grid, l, colMid, t, rowMid);
    root->topRight = construct(grid, colMid + 1, r, t, rowMid);
    root->bottomLeft = construct(grid, l, colMid, rowMid + 1, b);
    root->bottomRight = construct(grid, colMid + 1, r, rowMid + 1, b);
  }

  return root;
}
*/