class Solution {
public:

    TreeNode *helper(vector<int>&preorder,int &index,long max){
        if(index>preorder.size()-1||preorder[index]>max ) return nullptr;
        int nodeval=preorder[index];
        TreeNode* node=new TreeNode(nodeval);
        index++;
        node->left=helper(preorder,index,nodeval);
        node->right=helper(preorder,index,max);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index=0;
        return helper(preorder,index,LONG_MAX);


    }


};