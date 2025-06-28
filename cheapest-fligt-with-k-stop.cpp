#include<vector>
#include<iostream>
#include<map>
#include<queue>

using namespace std;

using _pair = pair<int, pair<int,int>>;

using min_heap = priority_queue<_pair, vector<_pair>, greater<_pair>>;



class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            
            // building adjancy list  
            vector<vector<pair<int,int>>>adj(n);
            for(const auto flight:flights){
                adj[flight[0]].push_back({flight[2], flight[1]});
            }
            
            // applying priority queue
            min_heap pq;
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            pq.push({0,{0,src}}); // stop dis node

            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();

                int flight_count = top.first;
                int dis = top.second.first;
                int node=top.second.second;

                if(dis==INT_MAX)
                    return -1;
                if(flight_count>k)
                    continue;
                
                for(auto _e:adj[node]){

                    int d = _e.first;
                    int n = _e.second;

                    if(dist[n]>d+dis &&flight_count<=k){
                        dist[n] = d + dis;
                        pq.push({flight_count+1,{dist[n],n}});
                    }
                }
            }

            return dist[dst] == INT_MAX ? -1:dist[dst];
        }
    };