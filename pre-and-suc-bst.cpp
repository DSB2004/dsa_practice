 void helper(TreeNode*root,int key,int&prev,int &suc){
    if(!root) return;
    if(root->data<key){
        prev=root->data;
        helper(root->right,key,prev,suc);
    }
    else if(root->data>key){
        suc=root->data;
        helper(root->left,key,prev,suc);
    }
    else {

        TreeNode* temp = root->left;
        while (temp) {
            pre = temp->data;
            temp = temp->right;
        }

        temp = root->right;
        while (temp) {
            suc = temp->data;
            temp = temp->left;
        }
        return;
    }

}


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    if(!root)return {-1,-1};
    int prev=-1;
    int suc=-1;
    helper(root,key,prev,suc);

    return {prev,suc};
}