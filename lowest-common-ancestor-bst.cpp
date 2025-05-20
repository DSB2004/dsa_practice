class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while(root!=nullptr){
                if(root->val==p->val ||root->val==q->val)return root;
                if((root->val>p->val &&root->val<q->val)||(root->val<p->val &&root->val>q->val)) return root;
                if((root->val<p->val)&&(root->val<q->val)) root=root->right;
                else root=root->left;
            }
            return root;
        }
    };