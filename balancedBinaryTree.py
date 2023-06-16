# Given a binary tree, determine if it is height-balanced
# A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

class Solution(object):
    def getDepth(self, root):
        if not root:
            return 0
        
        leftDepth = self.getDepth(root.left)
        rightDepth = self.getDepth(root.right)
        
        return max(leftDepth, rightDepth) + 1

    def isBalanced(self, root):
        if not root:
            return True
        
        leftDepth = self.getDepth(root.left)
        rightDepth = self.getDepth(root.right)

        if abs(leftDepth - rightDepth) > 1:
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)

# Explanation
# getDepth function from previous code
# Base case to check if root is empty, return TRUE since an empty tree is balanced
# Recursively calculated the depth of the left and right subtree
# If the absolute value of leftDepth - rightDepth is greater than 1, return false as the tree is not balanced
# Otherwise recursively check if both the left and right subtrees are balanced, eventually it will evaluate to false if it is not balanced
# If both subtrees evaluate to true, the tree is balanced
