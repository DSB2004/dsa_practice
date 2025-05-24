int tree_size(Node * root){
    stack <Node *> ref;
    int size=0;
    Node *cur=root;
    while(cur ||!ref.empty()){
        while(cur){
            ref.push(cur);
            cur=cur->left;
        }
            cur=ref.top();
            ref.pop();
            size++;
            cur=cur->right; 
    }
    return size;
}

int helper(Node * root,int target){
    stack <Node *> ref;
    int index=0;
    Node *cur=root;
    while(cur ||!ref.empty()){
        while(cur){
            ref.push(cur);
            cur=cur->left;
        }
            cur=ref.top();
            ref.pop();
            index++;
            if(index==target) return ref->data;
            cur=cur->right; 
    }
    return index;
}
int KthLargest(Node* root, int k)
{   
    // first calcuting the total height 

    int size=tree_size(root);
    int target=size-k+1;
    return helper(root,target);
}