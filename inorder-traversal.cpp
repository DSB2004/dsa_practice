class Solution {
    public:

    // with recursion
        void helper(TreeNode* root,vector<int>&ref){
            if(root==nullptr)return;
            helper(root->left,ref);
            ref.push_back(root->val);
            helper(root->right,ref);
            
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            helper(root,result);
            return result;
        }

    // morris traversal
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            TreeNode*cur=root;
            while(cur!=nullptr){
                if(cur->left==nullptr){
                    cur=cur->right;
                    result.push_back(cur->val);
                }
                else {
                    temp=cur->left;
                    while(temp->right!=nullptr||temp->right!=cur){
                        temp=temp->right;
                    }
                    if(temp->right==nullptr){
                        temp->right=cur;
                        cur=cur->left;
                    }
                    else{
                        temp->right=nullptr;
                        result.push_back(cur->val);
                        cur=cur->right;

                    }
                }
            }
            return result;
        }


    };