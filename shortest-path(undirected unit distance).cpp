#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:

    // given src=0

      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int> result(n,INT_MAX);
        queue<int> _ref;
        _ref.push(0);
        result[0]=0;

        while(!_ref.empty()){
            int front=_ref.front();
            int dis=result[front];
            _ref.pop();
            for(const auto &edge:adj[front]){
                if(result[edge]>dis+1){
                    result[edge]=dis+1;
                    _ref.push(edge); // we can only relax those array which are currently possible to be relaxed
                }
            }
        }

        for(auto &x:result){
            if(x==INT_MAX)x=-1;
        }

        return result;

        }
  };






