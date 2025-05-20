
#include <map>
#include <vector>
#include <queue>



using namespace std;
vector<int> bottomView(TreeNode<int> * root){
    vector<int> result;
    if(!root) return result;

    queue<pair<TreeNode<int>*,int>> q;
    
    map<int,int> m;

    q.push({root,0});

    while(!q.empty()){
        auto f=q.front();
        q.pop();
        TreeNode<int> * node=f.first;
        int v=f.second;

        m[v]=node->data;
        if(node->left){
            q.push({node->left,v-1});
        }
        if(node->right){
            q.push({node->right,v+1});
        }
    }
    

    for(auto &[v,val]:m){
        result.push_back(val);
    }

    return result;


}