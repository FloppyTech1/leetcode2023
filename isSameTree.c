// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL){
        return true;
    }
    if (p == NULL || q == NULL || p->val != q->val){
        return false;
    }

    bool leftSubtreeSame = isSameTree(p->left, q->left);
    bool rightSubtreeSame = isSameTree(p->right, q->right);

    return leftSubtreeSame && rightSubtreeSame;
}

// Explanation
// Check if both nodes are empty, return true
// Check if only of the nodes is empty, or both nodes have different values, return false
// Recursively check each pair of nodes and return the boolean values
