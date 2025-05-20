class Solution {
public:

    int maxHeightOfTree(TreeNode * root){
        if(root==nullptr)return 0;
        int left=maxHeightOfTree(root->left);
        int right=maxHeightOfTree(root->right);
        return 1+max(left,right);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int level=maxHeightOfTree(root);
        return static_cast<int>(pow(2,level-1));
        // get the max height 
        // minus 1 
        // return pow)2 ,height-1)

        
    }
};