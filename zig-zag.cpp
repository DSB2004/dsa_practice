class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;
            bool reverse=false;
            if(root==nullptr) return result;
            queue<TreeNode*> ref;
            ref.push(root);
            while(!ref.empty()){
                 int size=ref.size();
                 vector<int> r;
                 for(int i=0;i<size;i++){
                     TreeNode* head = ref.front();
                     ref.pop();
                     r.push_back(head->val);
                     if(head->left){
                         ref.push(head->left);
                     }
                     if(head->right){
                         ref.push(head->right);
                     }
                 }
                 if(reverse){
                    reverse(r.begin(),r.end());
                 }
                 result.push_back(r);
                 reverse=!reverse;
            }
 
            return result;
            
        }
    };