"""
bottom up, recursively return the result when treating itself as
left node or right node of its parent. When it's left node of its
parent, the len is consist from going to its right child node.
And vise versa. Also you can treat each node as a root of a subtree.
And when it's the root of a subtree, whether itself is left or right
doesn't matter. Hence you calculate the max_len accordingly

When single node, the answer is 0. Hence when there is no node,
it should return -1
"""


class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        max_len = 0

        def findZigZagLen(node: TreeNode, this_node_is_left: bool):
            nonlocal max_len
            if not node:
                return -1
            with_left = 1 + findZigZagLen(node.left, True)
            with_right = 1 + findZigZagLen(node.right, False)
            max_len = max(max_len, with_left, with_right)
            return with_right if this_node_is_left else with_left

        findZigZagLen(root, True)
        return max_len
