#include<vector>
#include<iostream>
#include<map>
#include<queue>
using namespace std;


using MinHeap = priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
>;


class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


            int m = grid.size();
            int n = grid[0].size();
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // 8 directional;
            
            if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;

            vector<vector<bool>> vis(m, vector<bool>(n, false));
            vis[0][0] = true;

            // using standard bfs  can be better here since the graph is of unit value 
            queue<pair<int,pair<int,int>>> pq;

            pq.push({0, {0, 0}});

            while(!pq.empty()){
                auto top = pq.front();
                pq.pop();

                int _d = top.first;
                auto node = top.second;
                int r = node.first;
                int c = node.second;
                
                if(r==m-1 &&c==n-1)
                return _d+1;
                for(auto d:dir){
                    int nr = d.first + r;
                    int nc = d.second + c;
                    int dis = _d + 1;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0&& !vis[nr][nc])
                        {
                        vis[nr][nc] =true;
                        pq.push({dis,{nr, nc}});
                    }
                    }
           }

           return -1;
        }
    };


class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


            int m = grid.size();
            int n = grid[0].size();
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // 8 directional;
            
            if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;

            vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
            dist[0][0] = 0;

            // using dijkstra  algo
            MinHeap pq;

            pq.push({0, {0, 0}});

            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();

                int _d = top.first;
                auto node = top.second;
                int r = node.first;
                int c = node.second;
                for(auto d:dir){
                    int nr = d.first + r;
                    int nc = d.second + c;
                    int dis = _d + 1;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0&& dist[nr][nc]>dis)
                    {
                        dist[nr][nc] =dis;
                        pq.push({dis,{nr, nc}});
                    }
                    }
           }

         return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1] + 1;

        }
    };