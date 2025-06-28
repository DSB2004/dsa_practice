#include<vector>
#include<iostream>
#include<map>
#include<queue>

// PENDING

using namespace std;

using _pair =  pair<int,int>;

using min_heap = priority_queue<_pair, vector<_pair>, greater<_pair>>;

class Solution {
   
    public:
        int countPaths(int n, vector<vector<int>>& roads) {

            vector<vector<_pair>> adj(n);

            for(auto road:roads){
                 // dis node
                adj[road[0]].push_back({road[2], road[1]});
                adj[road[1]].push_back({road[2], road[0]});
            }

            vector<int> dis(n,INT_MAX);
            vector<int> t(n,0);
            min_heap pq;

            // dis node
            pq.push({0, 0});

            t[0]=1;
            dis[0]=0;

            while(!pq.empty()){
                auto front = pq.top();
                pq.pop();

                int dis_ = front.first;
                int node_ = front.second;

                for(auto _n:adj[node_]){
                    if(dis[_n.second]>dis_+_n.first){
                        dis[_n.second] = dis_ +_n.first;
                        t[_n.second] = t[node_];
                        pq.push({dis[_n.second], _n.second});
                    }
                    else if(dis[_n.second]==dis_+_n.first){
                        t[_n.second]++;
                    }
                }
            }


            int result=0;
            const int MOD = 1e9 + 7;
            for (auto _t : t) {
                result = (result + _t) % MOD;
            }
            return result;
        }

    };