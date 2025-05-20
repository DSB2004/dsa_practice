class Solution {
    public:
        
    // recursive
      
    void _flatten(TreeNode* root,TreeNode *&prev) {
       if(!root) return;
       _flatten(root->right,prev);
       _flatten(root->left,prev);
       root->left=null;
       root->right=prev;
       prev=root; 
        }

    void flatten(TreeNode *root){
        TreeNode*prev=nullptr;
        return _flatten(root,prev);
    }


    // iterative 
    void flatten(TreeNode *root){
        TreeNode*prev=nullptr,*cur=root;
        stack<TreeNode*> ref;
        ref.push(root);
        while(!ref.empty()){
            TreeNode * cur=ref.top();
            ref.pop();
            if(!cur) continue;
            if(cur->right){
                ref.push(cur->right);
            }
            if(cur->left){
                ref.push(cur->left);
            }
            if(!ref.empty()) {
                cur->right=ref.top();
                cur->left=nullptr;
            }
        }        
    }


    };