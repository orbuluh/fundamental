/*
BST: For every node, "all" the values in its left subtree are less than the
node's value, and "all"" the values in its right subtree are greater than
the node's value.

Hence, given array nums, to form a BST by "inserting the elements of nums
in order into an initially empty BST", wll be a process like...

[3 4 5 1 2] -> first node is 3, root is 3
-> next node: 4, can only be right of 3
-> next node: 5, can only be right of 4
-> next node: 1, can only be left of 3
-> next node: 2, can only be right of 1

=> hence, it looks like      3
                         1        4
                           2        5

This implies, for a fixed root, the left subtree elements and the right
subtree elements are also fixed.
And in order to make it identical with original BST, we should keep the
relative order in left subtree elements and in right subtree elements.
E.g. for elements that are smaller than root, they will all be on the
left subtree. And as long as their relative ordering are the same in
the array, then the BST must be the same.

For example, [3 1 2 4 5] will make a same tree, as [1 2] are on the
                L L R R
left subtree, [4 5] are on the right subtree, and the still have the
same relative ordering respectively. Hence [3 1 4 2 5] will also
be the same BST.                              L R L R

So how many ways we can do this? It's a combination problem...

Say the answer is dfs(nums), and for the given nums,
- `leftSubree` has size `leftLen`
- `rightSubtree` has size `rightLen`

It will be like for the n - 1 locations in nums, (except for the root)
you need to pick leftLen locations to put the leftLen number in their
relative order. Then the remaining rightLen locations will naturally
be where the rightLen of nodes goes.

how many ways to pick these locations? C(n - 1, leftLen)
- which equas to C(n - 1, rightLen), as leftLen + rightLen = n - 1
- so consider leftLen side would be sufficient, as remaining locations
  for rightSubtree will be decided then.

And how many ways you can build the same leftSubtree? dfs(leftSubtree)
how many ways you can build the rightSubtree? dfs(rightSubtree)

Hence the recurssion is ....

dfs(nums) = C(n - 1, leftLen) * dfs(leftSubtree) * dfs(rightSubtree)

To speed up calculating the combinations, we could either prebuild a
Pascal triangle like table:

1 --C(0, 0)
1 1 --C(1, 0) C(1, 1)
1 2 1 --C(2, 0) C(2, 1) C(2, 2)
1 3 3 1 --C(3, 0) C(3, 1) C(3, 2) C(3, 3)

Or you can use recursion:

C(x, n) = C(x - 1, n) + C(x - 1, n - 1)

This formula represents the sum of two possibilities: not choosing the
current item and choosing n items from the remaining x-1 items
(dp[x-1][n]), and choosing the current item and then choosing n-1 items
from the remaining x-1 items (dp[x-1][n-1]).
*/

class Solution {
  static constexpr int mod = 1e9 + 7;
  int dp[1001][1001] = {};
  int comb(int x, int n) {
    return (x < n)    ? 0
           : n == 0   ? 1
           : n == 1   ? x
           : dp[x][n] ? dp[x][n]
                      : dp[x][n] = (comb(x - 1, n) + comb(x - 1, n - 1)) % mod;
  }

 public:
  int numOfWays(std::vector<int>& nums) { return dfs(nums) - 1; }
  long dfs(std::vector<int>& nums) {
    if (nums.size() <= 1) return 1;
    std::vector<int> left, right;
    const auto rootVal = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > rootVal) {
        right.push_back(nums[i]);
      } else {
        left.push_back(nums[i]);
      }
    }
    const auto lSz = left.size();
    const auto rSz = right.size();
    return ((dfs(left) * dfs(right) % mod) * comb(lSz + rSz, lSz)) % mod;
  }
};