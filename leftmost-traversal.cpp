#include<queue>

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> result;
    queue<BinaryTreeNode<int>*> ref;
    ref.push(root);
    int level=0;
    int cur=0;
    while(!ref.empty()){
        int size=ref.size();
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>*top=ref.front();
            ref.pop();
            if(cur==level){
                cur++;
                result.push_back(top->data);
            }
            if(top->left)ref.push(top->left);
            if(top->right)ref.push(top->right);
        }
        level++;
    }   
    return result;

}