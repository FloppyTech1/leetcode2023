# Given the root of a binary tree, return the length of the diameter of the tree.
# The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
# The length of a path between two nodes is represented by the number of edges between them.

class Solution(object):
    def getDepth(self, root):
        if not root:
            return 0
        
        leftDepth = self.getDepth(root.left)
        rightDepth = self.getDepth(root.right)
        
        return max(leftDepth, rightDepth) + 1

    def diameterOfBinaryTree(self, root):
        if not root:
            return 0       

        leftDiameter = self.diameterOfBinaryTree(root.left)
        rightDiameter = self.diameterOfBinaryTree(root.right)
        diameter = self.getDepth(root.left) + self.getDepth(root.right)
        diameter = max(diameter, max(leftDiameter, rightDiameter))

        return diameter

# Explanation
# Helper function to get depth (explained in previous code)
# Base case if root is empty return 0
# Recursively calculate the left and right subtrees
# Diameter is intialized to be the sum of the depth of the left and right subtrees
# Diameter is equal to the max num of the 3 numbers calculated
# Return diameter
