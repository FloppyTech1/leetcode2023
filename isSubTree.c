// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

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

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if (subRoot == NULL){
        return true;
    }
    if (root == NULL){
        return false;
    }
    if (isSameTree(root, subRoot)){
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Explanation
// isSameTree function from previous code
// If subRoot is an empty tree, it is a subtree
// If root is an empty tree, subRoot cannot be a subtree
// Use isSameTree to check if subroot exists at current nodes
// Recursively traverse the root tree to check all possible nodes
