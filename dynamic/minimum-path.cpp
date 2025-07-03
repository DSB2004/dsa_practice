#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:
        int helper(int m,int n,int i,int j,vector<vector<int>>&memo,const vector<vector<int>> &grid){
            if(i>=m ||j>=n){
                return INT_MAX;
            }
            if(memo[i][j]!=-1)
                return memo[i][j];
            if(i==m-1 && j==n-1){
                return grid[i][j];
            }

            memo[i][j]=grid[i][j] + min(helper(m, n, i + 1, j,memo, grid), helper(m, n, i, j + 1,memo, grid));
            return memo[i][j];
        }
        int minPathSum(vector<vector<int>>& grid) {

            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> memo(m, vector<int>(n, -1));
            return helper(grid.size(), grid[0].size(), 0, 0,memo, grid);
        }
    };