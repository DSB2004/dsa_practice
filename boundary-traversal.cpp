template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};
vector<int> traverseBoundary(TreeNode<int> *root)
{
    TreeNode<int>*cur=root;

    while(cur->left){
        
    }
}
