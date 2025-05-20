class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p==nullptr&&q==nullptr||p->val==q->val) return true;

            bool l=isSameTree(p->left,q->left);
            bool r=isSameTree(p->right,q->right);
            return l&&r;

        }
    };