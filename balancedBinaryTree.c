// Given a binary tree, determine if it is height-balanced
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

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

bool isBalanced(struct TreeNode* root){
    if (root == NULL){
        return true;
    }

    int depthLeft = maxDepth(root->left);
    int depthRight = maxDepth(root->right);

    if (abs(depthLeft - depthRight) > 1){
        return false;
    }
    else{
        return isBalanced(root->left) && isBalanced(root->right);
    }
}

// Explanation
// maxDepth function from previous code
// Base case to check if tree is empty, which is a balanced tree so we return true
// Recursively calculate the depth of the left and right subtrees
// If the absolute value of the difference between of trees is > 1, return false as the tree is not balanced
// Otherwise recursively check all nodes subtrees to be balanced, eventually it will return false if the tree is not balanced
// If both return true, the tree is balanced
