class Solution {
    public:
        void helper(TreeNode* root,vector<int>&ref){
            if(root==nullptr)return;
            helper(root->left,ref);
            helper(root->right,ref);
            ref.push_back(root->val);
            
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            helper(root,result);
            return result;
        }

        // using morris preorder

        vector<int> preorderTraversal(TreeNode*root){

            vector<int> result;
            TreeNode*cur=root;
            while(cur!=nullptr){
                if(cur->left==nullptr){
                    result.push_back(cur->val);
                    cur=cur->right;
                }
                else{
                    TreeNode*temp=cur->left;
                    while(temp->right!=nullptr&&temp->right!=cur)temp=temp->right;
                    
                    // hasn't been visited
                    if(temp->right==nullptr){
                        result.push_back(cur->val);
                        temp->right=cur;
                        cur=cur->left;
                    }
                    // it has been
                    else{
                        temp->right=nullptr;
                        cur=cur->right;
                    }
                }
            }
            return result;
        }
    };