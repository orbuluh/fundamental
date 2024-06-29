"""
you could also do bfs and get every last val ...
"""


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        def right_first(node, lvl):
            nonlocal res
            if not node:
                return
            if len(res) == lvl:
                # first time go to this level, and we go right
                # first, so this should be the right view
                res += [node.val]
            right_first(node.right, lvl + 1)
            right_first(node.left, lvl + 1)

        right_first(root, 0)
        return res
