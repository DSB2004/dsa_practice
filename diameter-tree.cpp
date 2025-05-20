class Solution {
    public:

    int helper(TreeNode* root,int &ans){
        if(!root)return 0;
        int l=diameterOfBinaryTree(root->left);
        int r=diameterOfBinaryTree(root->right);
        ans=max(ans,l+r);
        return 1+max(l,r);

    }
        int diameterOfBinaryTree(TreeNode* root) {
            int ans=0;
            helper(root,ans);
            return ans;
        }
    };