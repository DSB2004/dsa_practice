#include<vector>
#include<iostream>
#include<map>
#include<queue>


using namespace std;
using _pair = pair<int,int>;

using min_heap = priority_queue<_pair, vector<_pair>, greater<_pair>>;



class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int,int>>>adj(n+1);
            vector<int> distance(n+1,INT_MAX);
            distance[0]=0;
            distance[k]=0;
            for(const auto time:times){
                // sr -> wt , dst
                adj[time[0]].push_back({time[2], time[1]});
            }

            min_heap pq;

            pq.push({0, k});

            while(!pq.empty()){
                auto front = pq.top();
                pq.pop();

                int dist = front.first;
                int next = front.second;

                for(auto n:adj[next]){
                    int _dist = n.first;
                    int _next = n.second;
                    if(distance[_next]>_dist+dist){
                        distance[_next] = dist + _dist;
                        pq.push({distance[_next], _next});
                    }
                }
            }
            int max_=0;
            for(auto d:distance){
                if(d==INT_MAX)
                    return -1;
                max_ = max(max_, d);
            }
            return max_;
        }
    };