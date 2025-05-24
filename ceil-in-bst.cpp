int findCeil(BinaryTreeNode<int> *root, int X){
    int ceil=-1;
    while(root){
        if(root->data==X){ 
            return root->data;
        }
        else if(root->data>X){
            ceil=root->data;
            root= root->left;
        }
        else if (root->data<X){
            root=root->right;
         }
    }
    return ceil;
}