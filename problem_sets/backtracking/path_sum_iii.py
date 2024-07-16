"""
Idea is similar as Two sum, using hashmap to store:
- key : the prefix sum,
- val : how many ways get to this prefix su)

whenever reach a node, we check if prefix sum - target exists in hashmap or not,
if it does, we added up the ways of prefix sum - target into res.

E.g. if have seen x = (cur_sum - target) from path {A -> X}

then cur_sum - x = target means from path {next(X) -> cur_node} can contribute
to value target.

For example, targetSum 8, path [10, 5, 3], when we go to 10, we haven't seen
anything. When we go to 5, we have seen {10}, and cur_sum = 15. When we go to 3,
we have seen {10, 15}, cur_sum = 18, and because 18 - 8 = 10 is in seen, we know
that the total path {10 -> 5 -> 3} minus the path with sum 10, e.g. path {10},
can become a path that forms sum 8, e.g. path {5 -> 3}. So when you consider a
path, you can basically use prefix sum's concept to know whether a (sub)path
can form the targetSum.
"""


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        seen = defaultdict(int)
        # base cases so that when a direct path_sum from root is
        # targetSum, we can use seen[path_sum - targetSum] = 1 to
        # add one extra possible path
        seen[0] = 1
        ans = 0

        def dfs(node: TreeNode, path_sum):
            nonlocal ans
            if not node:
                return
            path_sum += node.val
            if path_sum - targetSum in seen:
                ans += seen[path_sum - targetSum]
            seen[path_sum] += 1
            dfs(node.left, path_sum)
            dfs(node.right, path_sum)
            # backtrack
            seen[path_sum] -= 1

        dfs(root, 0)
        return ans
