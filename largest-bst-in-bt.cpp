class Solution {
public:
    
    struct bstCheck{
        bool isBst;
        int min,max,sum;
    };
    bstCheck helper(TreeNode*node,int &result){
        if(!node) return {true,INT_MAX,INT_MIN,0};

        bstCheck left=helper(node->left,result);
        bstCheck right=helper(node->right,result);


        if(left.isBst&& right.isBst&& node->val>left.max&& node->val<right.min){
            int _new=left.sum+right.sum+node->val;

            result=max(result,_new);

            return {true,min(node->val,left.min),max(node->val,right.max),_new};
        }

        return {false,0,0,0};
    }
    
    int maxSumBST(TreeNode* root) {
        int result=0;
        helper(root,result);
        return result;
    }
};