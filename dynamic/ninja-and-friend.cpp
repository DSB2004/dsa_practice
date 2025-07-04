#include<iostream>
#include<vector>

using namespace std;



int helper(int level,int alice,int bob,vector<vector<vector<int>>> &memo,const vector<vector<int>>&grid){
    if (alice<0 ||bob<0|| alice >= grid[0].size()||bob>=grid[0].size())
        return INT_MIN;
    if (level == grid.size()-1)
        return memo[level][alice][bob];
    
    if(memo[level][alice][bob]!=-1)
        return memo[level][alice][bob];
    

    if(alice==bob){
       return  memo[level + 1][alice][bob] = grid[level][alice] + helper(level + 1, alice, bob, memo, grid);
    }
    int maxChoco = INT_MIN;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int nj1 = alice + dj1;
            int nj2 = bob + dj2;
            if (nj1 >=0 && nj1<grid[0].size() && nj2>=0 && nj2<grid[0].size()) {
                maxChoco = max(maxChoco, helper(level+1,nj1,nj2,memo,grid));
            }
        }
    }
    return maxChoco;
}
int maximumChocolates(int n, int m, vector<vector<int>> &grid){
    vector<vector<vector<int>>> memo(n,vector<vector<int>>(m, vector<int>(m, -1)));
    return helper(0, 0, m - 1, memo, grid);
}