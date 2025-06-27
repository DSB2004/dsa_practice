#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    public:

    bool dfs(int node ,vector<vector<pair<int,int>>> &list,stack<int>&result,vector<int>& visited){
        if(visited[node]==2) return true;
        if(visited[node]==1)return false;
        visited[node]=1;
        for(const auto &_pair:list[node]){
            int neighbour=_pair.first;
            int dis=_pair.second;
            if(!dfs(neighbour,list,result,visited))return false;
        }
        visited[node]=2;
        result.push(node);
        return true;
    }


    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          vector<vector<pair<int,int>>> list(V);
          vector<int> result(V,INT_MAX);
          vector<int> visited(V,0);
          stack<int> _ref;
          for(const auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int d=edge[2];
            list[u].push_back({v,d});
          }

          for(int i=0;i<V;i++){
            if(visited[i]!=0) continue;
            if(!dfs(i,list,_ref,visited))return result;
          }
          result[0] = 0;
          while(!_ref.empty()){

              int node=_ref.top();
            _ref.pop();
              if (result[node] == INT_MAX) continue;
              
            for(const auto &edge:list[node]){
                int neighbour=edge.first;
                int dis=edge.second;

                if(result[neighbour]>dis+result[node]){
                    result[neighbour]=dis+result[node];
                }


            }
          }
          for (int& x : result) {
            if (x == INT_MAX) x = -1;
        }
          return result;

    }
  };
  