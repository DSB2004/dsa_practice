#include<iostream>
#include <queue>
#include<vector>

using namespace std;

using _pair=pair<int,pair<int,int>>;
using min_heap=priority_queue<_pair,vector<_pair>,greater<_pair>>;

class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int v, vector<vector<int>> adj[]) {
        vector<bool>vis(v,false);
        min_heap pq;
        int sum=0;

        pq.push({0,{0,-1}});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int wt=top.first;
            int node=top.second.first;
            int par=top.second.second;

            if (vis[node]) continue;
            
            vis[node]=true;
            sum+=wt;

            for(auto edge:adj[node]){
                int next=edge[0];
                int nextWt=edge[1];
                if(!vis[next]){
                    pq.push({nextWt,{next,node}});
                }
            }      
        }
          
        return sum;
          
      }
  };