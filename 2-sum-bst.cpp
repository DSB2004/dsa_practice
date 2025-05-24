class Solution {
public:
// getting inorder and two pointer approach
    void inorder(TreeNode *root,vector<int> &result){
        TreeNode *cur=root;
        stack<TreeNode*> ref;
        while(cur ||!ref.empty()){
            while(cur){
                ref.push(cur);
                cur=cur->left;
            }
            if(!ref.empty()){
                cur=ref.top();
                ref.pop();
                result.push_back(cur->val);   
                cur=cur->right;
            }
        }
        return;
    }

    // using set 
    bool findTarget(TreeNode* root, int k) {
        TreeNode *cur=root;
        stack<TreeNode*> ref;
        unordered_set<int> seen;
        while(cur ||!ref.empty()){
            while(cur){
                ref.push(cur);
                cur=cur->left;
            }
            if(!ref.empty()){
                cur=ref.top();
                ref.pop();
                if(seen.find(k-cur->data)!=seen.end()) return true
                seen.insert(cur->data);  
                cur=cur->right;
            }
        }
        return false;

    }
// using bst iterator and two pointer 

    
int next(stack<TreeNode *> & nextStack){
      
        TreeNode * top=nextStack.top();
        nextStack.pop();
        TreeNode *_top = top->right;
        while (_top) {
            nextStack.push(_top);
            _top = _top->left;
        }
        return top->val;
    }

    int before(stack<TreeNode *> & beforeStack){
        TreeNode * top=beforeStack.top();
        beforeStack.pop();
       
        TreeNode *_top = top->left;
        while (_top) {
            beforeStack.push(_top);
            _top = _top->right;
        }

        return top->val;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> _next,_before;

        TreeNode *cur=root;

        while(cur){
            _next.push(cur);
            cur=cur->left;
        }
        cur=root;
        while(cur){
            _before.push(cur);
            cur=cur->right;
        }


        int i=next(_next);
        int j=before(_before);

     while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) {
                if (_next.empty()) break; 
                i = next(_next);
            } else {
                if (_before.empty()) break; 
                j = before(_before);
            }
        }

        return i+j==k;
    }
};