class BSTIterator {
public:
    Stack<TreeNode*> space;

    BSTIterator(TreeNode* root) {
        while(root!=nullptr){
            space.push(root);    
            root=root->left;
        }
    }
    
    int next() {
        TreeNode * top=space.top();
        space.pop();
        if(top->right){
            TreeNode *_top=top;
            while(_top!=nullptr){
                space.push(_top);
                _top=_top->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        return !space.empty();
    }
};
