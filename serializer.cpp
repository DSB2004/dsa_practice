//  pending 

class Codec {
public:

   void split(const string& data, vector<string>& result) {
    int i=0;
    int j=0;
    int n=data.size();
    while(j<n){
        while(j<n && data[j]!='>') j++;
        result.push_back(data.substr(i,j-i));
        j++;
        i=j;
        }   
    }

    TreeNode * construct(vector<string>&vals,int&index){
        if(index>=vals.size()||vals[index]=="null") 
        {   
            index++;
            return nullptr;
        }
        int nodeVal=stoi(vals[index]);
        TreeNode * node=new TreeNode(nodeVal);
        index++;
        node->left=construct(vals,index);
        node->right=construct(vals,index);

        return node;
    }
    void preorder(TreeNode*node,string&result){
         
        if(!node){
            result+="null>";
            return ;
        }
        result+=to_string(node->val);
        result+=">";
        preorder(node->left,result);
        preorder(node->right,result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string result;
        preorder(root,result);
        if (!result.empty()) result.pop_back(); // to remove > from end
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;

        vector<string>inorder;
        split(data,inorder);
        int index=0;
        return construct(inorder,index);
        
    }
};