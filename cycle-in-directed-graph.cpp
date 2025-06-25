#include<vector>
#include<iostream>
#include<queue>
using namespace std;

// bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

             
//     vector<int> indegree(numCourses, 0);

//      for(auto const &prerequisite:prerequisites){
//          indegree[prerequisite[0]]++;
//      }
//      int i = 0;
//      int count = 0;
//      while(i<numCourses){
//          if(i!=0)
//              count++;
//          i++;
//      }
//      return count != numCourses;
//  }




int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges){
    // using kahn's algorithms

    queue<int> _queue;
    vector<int> indegree(n+1, 0);
    vector<vector<int>> list(n+1);

    for(auto const &edge:edges){
        auto a = edge.first;
        auto b = edge.second;
        indegree[b]++;
        list[a].push_back(b);
    }

    for (int i = 1; i < n+1;i++){
        if(indegree[i]==0){
            _queue.push(i);
        }
    }
    int count = 0;
    while(!_queue.empty()){
        int front = _queue.front();
        _queue.pop(); 
        count++;
        for(auto edge:list[front]){
            indegree[edge]--;
            if(indegree[edge]==0){
                _queue.push(edge);
            }
        }
    }
    return count!=n;
}

#include<stack>

bool dfs(int node,vector<vector<int>>&list,vector<int>&visited){
    
    if(visited[node]==1)
        return true;
    if(visited[node]==2)
        return false;

    visited[node] =1;

    for(auto const &edge:list[node]){
        if(dfs(edge,list,visited))
            return true;
        
    }
    visited[node] =2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges){
    
    
    vector<vector<int>> list(n+1);
    vector<int> visited(n + 1, 0);

    for(auto const &edge:edges){
        auto a = edge.first;
        auto b = edge.second;
        list[a].push_back(b);
    }


    for (int i = 1; i < n+1;i++){
        if (visited[i] == 0) {
            if (dfs(i, list, visited)) {
                return true;
            }
        }
    }
    return false;
}