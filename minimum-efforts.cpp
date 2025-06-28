#include<vector>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

using _pair = pair<int, pair<int, int>>;

using min_heap = priority_queue<_pair, vector<_pair>, greater<_pair>>;

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            min_heap pq;
            int m = heights.size();
            int n = heights[0].size();

            vector<pair<int, int>>
                dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            pq.push({0,{0,0}});

            vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();

                int _d = top.first;
                auto node = top.second;
                int r = node.first;
                int c = node.second;
                for(auto d:dirs){
                    int nr = d.first + r;
                    int nc = d.second + c;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                        {
                        int stepEffort = abs(heights[nr][nc] - heights[r][c]);
                        int maxEffort = max(_d, stepEffort);
                        if(dis[nr][nc]>maxEffort){
                            dis[nr][nc] =maxEffort;
                            pq.push({maxEffort,{nr, nc}});
                        }
                    }
                    }
           }
           return dis[m - 1][n - 1] == INT_MAX ? -1 : dis[m - 1][n - 1];
            
        }
    };