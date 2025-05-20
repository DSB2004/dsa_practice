class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            
            while(root!=nullptr){

                int rootVal=root->val;
                if(rootVal==val){
                    return root;
                }
                
                if(rootVal>root){
                    root=root->right;
                }
                else {
                    root=root->left;
                }
            }
            return root;
        }
    };