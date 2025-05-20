class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(p==root&&q==root)return root;
            if(p==q) return p;

            stack<TreeNode*>ref;

            TreeNode*cur=nullptr;

            ref.push_back(root);
            while(true){
                cur=ref.top();
                ref.pop()
                if(cur==nullptr)continue;
                if(cur==p) break;
                ref.push_back(cur->right);
                ref.push_back(cur->left);
            }


        }
    };