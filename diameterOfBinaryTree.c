// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

int maxDepth(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth){
        return leftDepth + 1;
    }
    else{
        return rightDepth + 1;
    }
}

int diameterOfBinaryTree(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }
    int max = 0;
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);
    int diameter = maxDepth(root->left) + maxDepth(root->right);
    if (leftDiameter > rightDiameter){
        max = leftDiameter;
    }
    else{
        max = rightDiameter;
    }

    if (max > diameter){
        return max;
    }
    else{
    return diameter;
    }
}

// Explanation
// MaxDepth function from previous code
// Base case to check if root is NULL
// Initialize a max variable for later
// Recurisvely calculate the left and right subtrees
// Initialize diameter as the sum of the depth of the left and right subtrees
// Compare left, right and diameter and return the largest
