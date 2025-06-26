#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
            queue<pair<pair<int,int>,int>>_queue;  // pos dis
            int m=mat.size();
            int n=mat[0].size();
            
            vector<vector<bool>>visited(m,vector<bool>(n));

            for(int i=0;i<m;i++){

                for(int j=0;j<n;j++){
                    if(mat[i][j]==0){
                        visited[i][j]=true;
                        _queue.push({{i,j},0});
                    }

                }
            }

            while(!_queue.empty()){
                auto front=_queue.front();
                _queue.pop();
                int pos_i=front.first.first;
                int pos_j=front.first.second;
                int dis=front.second;
                for(auto dir:dirs){
                    int r=dir[0];
                    int c=dir[1];
                    int nr = pos_i + r;
                    int nc = pos_j + c;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&!visited[nr][nc]) {
                        mat[nr][nc]=dis+1;
                        visited[nr][nc]=true;
                        _queue.push({{nr,nc},dis+1});
                        }
                    
                }


            }        
            return mat;
        }

        
    };