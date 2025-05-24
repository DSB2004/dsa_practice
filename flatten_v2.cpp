class Solution {
public:
    void helper(TreeNode*root,TreeNode *&prev){
        if(!root) return;

        helper(root->right,prev);
        helper(root->left,prev);
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
    void flatten(TreeNode* root) {
        TreeNode * prev=nullptr;
        return helper(root,prev);
    }
};