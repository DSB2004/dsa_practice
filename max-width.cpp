class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // node , index
        queue<pair<TreeNode*,unsigned long long >> q;
        int result=0;
        q.push({root,0});

        while(!q.empty()){
            int size=q.size();
            unsigned long long first=q.front().second;
            unsigned long long last=q.back().second;
            
            result=max(result,static_cast<int>(last-first+1));

            for(int i=0;i<size;i++){
                auto [node, index] = q.front();
                q.pop();
                if (node->left)
                    q.push({node->left, index * 2});
                if (node->right)
                    q.push({node->right, index * 2 + 1});


            }
        }
        return result;
    }
};