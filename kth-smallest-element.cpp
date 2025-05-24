class Solution {
public:
    void helper(TreeNode *node,int k,int &index,int &ans){
        if(!node) return;
        helper(node->left,k,index,ans);
        index++;
        if(k==index){
            ans=node->val;
        }
        helper(node->right,k,index,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int index=0;
        int result=root->val;
        helper(root,k,index,result);
        return result;
    }
};