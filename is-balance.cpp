class Solution {
    public:
        int helper(TreeNode*root,bool &ans){
            if(!root) return 0;

            int l=helper(root->left,ans);
            int r=helper(root->right,ans);

            ans&=(l==r||abs(l-r)==1);
            return 1+max(l,r);

        }
        bool isBalanced(TreeNode* root) {
            bool result=true;
            helper(root,result);
            return result;
        }
    };