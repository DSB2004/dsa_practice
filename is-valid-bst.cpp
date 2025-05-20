class Solution {
    public:
        bool isLeaf(TreeNode* root){
            return root->left==nullptr&&root->right==nullptr;
        }
        bool helper(TreeNode *root,int left_limit,int right_limit){

            if(!root) return true;
           
            if(root->val<=left_limit ||root->val>=right_limit) return false;
            return  helper(root->left,left_limit,root->val) &&helper(root->right,root->val,right_limit);
        }
        bool isValidBST(TreeNode* root) {
            return helper(root,INT_MIN,INT_MAX);
        }
    };