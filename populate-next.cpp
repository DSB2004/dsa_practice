class Solution {
    public:
    
        Node* connect(Node* root) {
            if(!root) return root;
           
            queue<Node*> ref;
            vector<vector<Node*>>v;


            ref.push(root);

            while(!ref.empty()){
                int size=ref.size();
                vector<Node *> temp;
                for(int i=0;i<size;i++){
                    Node *top=ref.front();
                    ref.pop();
                    temp.push(top);
                    if(top->left) ref.push(top->left);
                    if(top->right) ref.push(top->right);
                }
                v.push_back(temp);
            }
            
            for(auto row:v){
                for(int i=0;i<row.size();i++){
                    Node * cur=row[i];
                    if(i==row.size()-1){
                        cur->next=nullptr;
                    }
                    else{
                        cur->next=row[i+1];
                    }
                }
            }
            return root;
        }

     // optimised version 
                Node* connect(Node* root) {
                    if (!root) return root;
            
                    queue<Node*> q;
                    q.push(root);
            
                    while (!q.empty()) {
                        int size = q.size();
                        Node* prev = nullptr;
                        for (int i = 0; i < size; ++i) {
                            Node* cur = q.front();
                            q.pop();
            
                            if (prev) prev->next = cur;
                            prev = cur;
            
                            if (cur->left) q.push(cur->left);
                            if (cur->right) q.push(cur->right);
                        }
                        prev->next = nullptr;
                    }
            
                    return root;
                }
            
            
    };