#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:
      
        int helper(int m,int n,int i,int j,const vector<vector<int>>&grid,vector<vector<int>>&count){
            if(i<0 ||i>=m ||j<0||j>=n || grid[i][j]==1)
                return 0;
            if(i==m-1 && j==n-1)
                return 1;
            if(count[i][j]!=-1)return count[i][j];
            int a = 0, b = 0;
            a = helper(m, n, i + 1, j,grid, count);

            b=helper(m, n, i, j + 1,grid, count);
            count[i][j]=a + b;
            return count[i][j];
        }
        
        int uuniquePathsWithObstacles(vector<vector<int>> grid) {
            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> count(m, vector<int>(n, -1));
            return helper(m, n, 0, 0, grid,count);
            
        }
    };