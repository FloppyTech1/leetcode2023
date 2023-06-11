// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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

// Explanation
// Start with a base case to check if the tree/root/node is empty (can't have a path or extend it if it's empty)
// Recursively calculate the left and right depths
// Compare both results and return the greater + 1 to include the root
