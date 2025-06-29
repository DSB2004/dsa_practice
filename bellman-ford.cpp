#include<vector>
#include<iostream>

using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

   vector<int> dis(n + 1, INT_MAX); 
    dis[src] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dis[u] != INT_MAX && dis[u] + wt < dis[v]) {
                dis[v] = dis[u] + wt;
            }
        }
    }
}