#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_set<int> visited;
    vector<int> result;
    queue<int> _queue;
    if(adj.size()==0) return result;
    _queue.push(0);

    while(!_queue.empty()){
        int _front=_queue.front();
        _queue.pop();
        if(visited.find(_front)==visited.end()){
            visited.insert(_front);
            result.push_back(_front);
            
            for(auto n:adj[_front]){
                
                _queue.push(n);
            }
        }
    }
    return result;
}