bool isLeaf(BinaryTreeNode<int> *node) {
    return node->left == nullptr && node->right == nullptr;
}

void helper(BinaryTreeNode<int> *node, string &prev, vector<string> &result) {
    if (!node) return;

    string curr = (prev.empty() ? "" : " ") + to_string(node->data);
    prev += curr;

    if (isLeaf(node)) {
        result.push_back(prev);
    } else {
        helper(node->left, prev, result);
        helper(node->right, prev, result);
    }

    prev.erase(prev.size() - curr.size()); 
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root) {
    vector<string> result;
    string prev;
    helper(root, prev, result);
    return result;
}
