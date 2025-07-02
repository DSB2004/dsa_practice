#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class disjoint_set{

    vector<int> rank;
    vector<int> par;

    public:
    disjoint_set(int n){
        rank.resize(n, 0);
        par.resize(n);
        for (int i = 0; i <n; i++)
        {
            par[i] = i;
        }
    }

    public:
    
    int find_par(int u){
        if(u==par[u]) return par[u];
        return par[u]=find_par(par[u]);
    }

    void union_set(int u,int v){
        int p_u = find_par(u);
        int p_v = find_par(v);

        if(p_u==p_v)
            return;
        
        if(rank[p_u]>rank[p_v]){
            par[p_v] = p_u;
        }
        else if(rank[p_v]>rank[p_u]){
            par[p_u] = p_v;
        }
        else{
            par[p_v] = p_u;
            rank[p_u]++;
        }
    }

};

using _pair = pair<int,pair<int, int>>;
using min_heap = priority_queue<_pair, vector<_pair>, greater<_pair>>;

class Solution {
    
    public:
      int kruskalsMST(int V, vector<vector<int>> &edges) {
          min_heap pq;
          disjoint_set ds(V);

          for(const auto&edge:edges){
              int src = edge[0];
              int dst = edge[1];
              int wt = edge[2];

              pq.push({wt, {src, dst}});
          }
          int result = 0;

          while(!pq.empty()){
              auto front = pq.top();
              pq.pop();
              int src = front.second.first;
              int dst = front.second.second;
              int wt = front.first;
              if(ds.find_par(src)==ds.find_par(dst))
                continue;
              result += wt;
              ds.union_set(src, dst);
          }
          return result;
        }
  };