"""
need to analyze the possible situations....


Say we want to delete node a

1. delete a node without children -> simply return None for itself
2. delete a node with only left child ->
    simply replace left node with the deleted node

    x             x
       a   --->     b
     b

3. delete a node with only right child ->
    simply replace right node with the deleted node

    x               x
       a     -->       b
         b

4. delete a node with both left and right nodes ...
    need to find the left most of the node and swap it
    as the left most of node is the predecessor between
    the deleted node and its parent, given the property
    of BST.
    Also, if left most node c has right tree y, that
    right tree should basically becomes where c used
    to be .. . which has the effect of delete c itself

    x               x
       a     -->       c
    ...    b         ...  b
    c                y
      y
"""


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return root
        if root.val == key:
            if not root.left and not root.right:
                return None
            elif root.left and not root.right:
                return root.left
            elif not root.left and root.right:
                return root.right
            else:
                node = root.right
                while node.left:
                    node = node.left
                root.val = node.val  # swap the value
                root.right = self.deleteNode(root.right, root.val)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            root.left = self.deleteNode(root.left, key)
        return root
