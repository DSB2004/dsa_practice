class Solution {
public:
  class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // following depth first search technique
        if (root == nullptr || root == p || root == q) return root;
        auto left=lowestCommonAncestor(root->left,p,q);
        auto right=lowestCommonAncestor(root->right,p,q);
        if(left &&right){
            return root;
        }
        if(left)return left;
        return right;
    }
};
};