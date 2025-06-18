#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;


vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{   
    vector<vector<int>> adj(v);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    unordered_set<int> visited;
    vector<vector<int>> result;

    stack<int> _stack;

    for(int i=0;i<v;i++){
        if(visited.find(i)!=visited.end())continue;
        _stack.push(i);
        vector<int>temp;
        while(!_stack.empty()){
            int top=_stack.top();
            _stack.pop();
            if(visited.find(top)!=visited.end())continue;
            visited.insert(top);
            temp.push_back(top);
            for(auto n:adj[top]){
                if(visited.find(n)!=visited.end())continue;
                _stack.push(n);
            }
        }
        result.push_back(temp);
    }

    return result;

    
}