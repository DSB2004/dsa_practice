#include<unordered_map>

class Solution {
    //  0(n^2)
    public:
        TreeNode *helper(vector<int>& preorder, vector<int>& inorder,int &preorder_pos,int inorder_start,int inorder_end){
            if(inorder_start>inorder_end || preorder_pos>=preorder.size()) return nullptr;
            
            int root_val=preorder[preorder_pos];

            TreeNode * node=new TreeNode(root_val);

            preorder_pos++;

            int i=inorder_start;
            while (inorder[i]!=root_val &&i<=inorder_end) i++;

            TreeNode * left=helper(preorder,inorder,preorder_pos,inorder_start,i);
            preorder_pos++;
            TreeNode *right=helper(preorder,inorder,preorder_pos,i+1,inorder_end);

            node->left=left;
            node->right=right;

            return node;
            
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preorder_pos=0;
            return helper(preorder,inorder,preorder_pos,0,inorder.size()-1);
        }

        // O(nlogn)

      
                TreeNode *helper(vector<int>& preorder, map<int,int> &inorder_map,int &preorder_pos,int inorder_start,int inorder_end){
                    if(inorder_start>inorder_end || preorder_pos>=preorder.size()) return nullptr;
                    
                    int root_val=preorder[preorder_pos];
        
                    TreeNode * node=new TreeNode(root_val);
        
                    preorder_pos++;
        
                    int i=inorder_map[root_val];
        
                    TreeNode * left=helper(preorder,inorder_map,preorder_pos,inorder_start,i-1);
                    TreeNode *right=helper(preorder,inorder_map,preorder_pos,i+1,inorder_end);
        
                    node->left=left;
                    node->right=right;
        
                    return node;
                    
                }
                TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                    int preorder_pos=0;
                    map<int,int> refInorder;
                    for(int i=0;i<inorder.size();i++){
                        refInorder[inorder[i]]=i;
                    }
                    return helper(preorder,refInorder,preorder_pos,0,inorder.size()-1);
                }
            
    };