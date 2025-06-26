#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:


    
        void helper(int i,int j,vector<vector<int>>&board,vector<vector<bool>>& visited){
            int m=board.size();
            int n=board[0].size();
            if(i<0 ||j<0 ||i>=m||j>=n||visited[i][j]||board[i][j]!=1)return;
            visited[i][j]=true;
            board[i][j]=-1;
            helper(i+1,j,board,visited);
            helper(i-1,j,board,visited);
            helper(i,j-1,board,visited);
            helper(i,j+1,board,visited);
            return;
        }

        int numEnclaves(vector<vector<int>>& grid) {

            int m=grid.size();
            int n=grid[0].size();
            vector<vector<bool>>visited(m,vector<bool>(n));

            for (int i = 0; i < m; i++) {
                if (grid[i][0] == 1) {
                    helper(i, 0, grid, visited);
                }
                if (grid[i][n - 1] == 1) {
                    helper(i, n - 1, grid, visited);
                }
            }

            for (int j = 0; j < n; j++) {
                if (grid[0][j] == 1) {
                    helper(0, j, grid, visited);
                }
                if (grid[m - 1][j] == 1) {
                    helper(m - 1, j, grid, visited);
                }
            }

            int count=0;

            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                       count++;
                    }
                   
                }
    
            }
            return count;
        }

    };