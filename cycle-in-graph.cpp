

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// using BFS

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    queue<pair<int,int>> _queue;
    vector<bool> visited(n+1,false);

    vector<vector<int>>adj(n+1);
    for(auto edge:edges){
        int i=edge[0];
        int j=edge[1];
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
    for(int i=1;i<n;i++){
        if(visited[i])continue;
        _queue.push({i,-1});
        while(!_queue.empty()){
            int num = _queue.front().first;
            int par = _queue.front().second;
            visited[num]=true;
            _queue.pop();
            
            for(auto n:adj[num]){
                if(!visited[n]){
                    visited[n]=true;
                    _queue.push({n,num});
                }
                else if(n!=par) {
                    return "Yes";
                }
            }
        }
        
    }
        return "No";
}


// using DFS

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    stack<pair<int,int>> _stack;
    vector<bool> visited(n+1,false);

    vector<vector<int>>adj(n+1);
    for(auto edge:edges){
        int i=edge[0];
        int j=edge[1];
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    
    for(int i=1;i<n;i++){
        if(visited[i])continue;
        _stack.push({i,-1});
        while(!_stack.empty()){
            
            int num = _stack.top().first;
            int par = _stack.top().second;
            visited[num]=true;
            _stack.pop();
            
            for(auto n:adj[num]){
                if(!visited[n]){
                    visited[n]=true;
                    _stack.push({n,num});
                }
                else if(n!=par) {
                    return "Yes";
                }
            }
        }
        
    }
        return "No";
}
