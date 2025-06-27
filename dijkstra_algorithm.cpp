#include<iostream>
#include <queue>
#include<vector>


using namespace std;

class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        vector<vector<pair<int,int>>> adj(V);

        vector<int>result(V,INT_MAX);
        for(const auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }

        minHeap.push({0,src});
        result[src] = 0;

        while(!minHeap.empty()){
            auto front=minHeap.top();
            minHeap.pop();
            int n=front.second;
            int d=front.first;

            if(d>result[n])continue;

            for(const auto &edge:adj[n]){
                int ne=edge.first;
                int w=edge.second;

                if(result[ne]>d+w){
                    result[ne]=d+w;
                    minHeap.push({d+w,ne});
                }
            }
        }
return result;


      }
  };