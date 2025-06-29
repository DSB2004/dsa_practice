#include<iostream>
#include <queue>
#include<vector>


using namespace std;

class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<int> count(n,0);

            // constructing a adjancy matrix
            vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
            
            for(auto edge:edges){
                int src=edge[0];
                int dst=edge[1];
                int wt=edge[2];
                dist[src][dst]=wt;
                dist[dst][src]=wt;
            }

            for(int i=0;i<n;i++){
                dist[i][i]=0;
            }
            
            // first calculating the shortest path for each city from each other city

            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for (int j = 0; j < n; j++)
                    {
                        if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                        }
                    }
                    
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && dist[i][j]<=distanceThreshold){
                        count[i]++;
                    }
                }
            }
            int ans=0,min_=count[0];
            for(int i=0;i<n;i++){
                 if (count[i] < min_ || (count[i] == min_ && i > ans)) {
                    min_=count[i];
                    ans=i;
                }
            }
            return ans;
        }
    };