// Given the root of a binary tree, invert the tree, and return its root.

struct TreeNode* invertTree(struct TreeNode* root){
        if (root == NULL){
        return 0;
    }
    
    struct TreeNode* temp = root->left;

    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root; 
}

// Explanation
// If the root is NULL we return 0 (there's no tree)
// Initialize a temporary variale to story the left node
// Swap the left node for the right node
// Swap the right node for the left node
// Recursively do this (first will be instances of root->left, then instances of root->right)
// Finally return the root
