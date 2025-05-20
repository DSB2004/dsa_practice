class Solution {
    public:
        
        TreeNode* helper(vector<int>& postorder,map<int,int>&inorder_map,int &pos,int  inorder_start,int inorder_end) {
            if(inorder_start>inorder_end || pos<0) return nullptr;

            int root_val=postorder[pos];
            pos--;
            TreeNode * root=new TreeNode(root_val);

            int root_pos=inorder_map[root_val];

            root->right=helper(postorder,inorder_map,pos,root_pos+1,inorder_end);
            root->left=helper(postorder,inorder_map,pos,inorder_start,root_pos-1);
            
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int pos=postorder.size()-1; 
            map<int,int> inorder_map;
            for(int i=0;i<inorder.size();i++){
                inorder_map[inorder[i]]=i;
            }
            return helper(postorder,inorder_map,pos,0,inorder.size()-1);
        }
    };