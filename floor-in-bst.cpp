int floorInBST(TreeNode<int> * root, int X)
{
    int floor=-1;
    while(root){
        if(root->data==X) return root->data;
        else if(root->data>X)root= root->left;
        else if (root->data<X){root=root->right;floor=root->data; } 
        else break;
    }
    return floor;
}