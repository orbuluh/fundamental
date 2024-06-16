# You only need to split to 2 sub-trees. So if you know the sum of a subtree
# from a node, and you also know the total tree node sum, then you know what
# is the product of this case. Taking further, you don't even need to know
# what is the subtree nodes sum - once you know the total tree node sum, you
# only need to know all the possible subtree node sum, regardless of the tree
# structure! So you don't need to traverse tree twice! Once is enough.


class Solution:
    def __init__(self):
        self.subSum = []

    def subTreeSum(self, node: TreeNode) -> int:
        if not node:
            return 0
        rec_res = node.val + self.subTreeSum(node.left) + self.subTreeSum(node.right)
        self.subSum += [rec_res]
        return rec_res

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        totalSum = self.subTreeSum(root)
        return max([s * (totalSum - s) for s in self.subSum]) % 1000000007
