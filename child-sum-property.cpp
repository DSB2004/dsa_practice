bool isLeaf(BinaryTreeNode<int> *root) {
    return root && root->left == nullptr && root->right == nullptr;
}

void changeTree(BinaryTreeNode<int> *root) {
    if (!root || isLeaf(root)) return;

    int child_sum = 0;
    if (root->left) child_sum += root->left->data;
    if (root->right) child_sum += root->right->data;

    if (child_sum < root->data) {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    // Step 2: Recursive Calls
    changeTree(root->left);
    changeTree(root->right);

    // Step 3: Bottom-Up Adjustment
    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;
    if (root->left || root->right) root->data = total;
}
