#include<iostream>
#include<vector>

using namespace std;


int helper(int level,int prev,vector<vector<int>> &points,vector<vector<int>> &memo)
{
    if(level>=points.size()){
        return 0;
    }
    if(prev>=0 && memo[level][prev]!=-1){
        return memo[level][prev];
    }

    int merit = -1e9;
    for (int i = 0; i <3;i++){
        if(prev==i)
            continue;
        else{
            merit=max(merit, points[level][i] + helper(level + 1, i, points,memo));
        }
    }
    if(prev>=0){
    memo[level][prev]=merit;
    }
    return merit;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>memo(n,vector<int>(3,-1));
    return helper(0, -1, points,memo);
}